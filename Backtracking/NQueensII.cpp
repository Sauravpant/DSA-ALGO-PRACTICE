#include<bits/stdc++.h>
using namespace std;
class Solution{
    int count=0;
    void solve(int col,vector<string>&board,vector<int>&cRow,vector<int>&cUp,vector<int>&cLower,int n){
        if(col==n-1){
            count++;
            return;
        }
        for (int row=0;row<n;row++)
        {
            if(cRow[row]==0 && cUp[row+col]==0 && cLower[(n-1)+row-col]==0){
                board[row][col]='Q';
                cRow[row]=1; 
                cUp[row+col]=1;
                cLower[(n-1)+row-col]=1;
                solve(col+1,board,cRow,cUp,cLower,n);
                board[row][col]='.';
                cRow[row]=0; 
                cUp[row+col]=0;
                cLower[(n-1)+row-col]=0;
            }
        }
    }
    public:
    int NQueens(int n){
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<board.size();i++)
        board[i]=s;
        vector<int> checkRow(n,0);
        vector<int> checkUpperDiagonal(2*n-1,0);
        vector<int> checkLowerDiagonal(2*n-1,0);
        solve(0,board,checkRow,checkLowerDiagonal,checkUpperDiagonal,n);
        return count;
    }


};