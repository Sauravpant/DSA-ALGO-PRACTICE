/*
51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 
*/
//Solution:      Backtracking approach:
//A queen can attack in all 8 directions in a chess board but since we are placing Queens from the leftmost column there is no need to check if right 
//side is safe or not. Since we can place only one queen in column and a row and also they should not cancel out each other. so we should check if
//there is a Queen in corresponding left row,left upper diagonal and left lower diagonal or not.If so we cant place  a queen there .Instead of using 3 loops 
//to check whether these places are safe or not we try to fill up an array whenever we place a queen at any position . For a row,if any row is marked as
// 1 ,next time if we try to place a queen at that row of any column it will be marked as 1 and we cant place a queen there similarly for lower diagonal 
//if any row+col is marked as 1 ,at any column of a row the sum of row and column will be same as previous one if it is the cutting diagonal of that one
// Similarly for upper diagonal n-1+row-col will be same for cutting diagonals. We iterate at each row of col,if it is safe we place a queen and move to 
//next column. If that particular move leads to an unsafe move we backtrack and try with another row.If at any instant we reach at last column and place
// a queen there we return as we have placed the queens successfully and try if there exists any other solution.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&cRow,vector<int>&cUp,vector<int>&cLower,int n){
        if(col==n-1){
            ans.push_back(board);
            return;
        }
        for (int row=0;row<n;row++)
        {
            if(cRow[row]==0 && cUp[row+col]==0 && cLower[(n-1)+row-col]==0){
                board[row][col]='Q';
                cRow[row]=1; 
                cUp[row+col]=1;
                cLower[(n-1)+row-col]=1;
                solve(col+1,board,ans,cRow,cUp,cLower,n);
                board[row][col]='.';
                cRow[row]=0; 
                cUp[row+col]=0;
                cLower[(n-1)+row-col]=0;
            }
        }
    }
    public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<board.size();i++)
        board[i]=s;
        vector<int> checkRow(n,0);
        vector<int> checkUpperDiagonal(2*n-1,0);
        vector<int> checkLowerDiagonal(2*n-1,0);
        solve(0,board,ans,checkRow,checkLowerDiagonal,checkUpperDiagonal,n);
        return ans;
    }
};