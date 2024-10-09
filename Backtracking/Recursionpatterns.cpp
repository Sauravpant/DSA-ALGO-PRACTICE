
#include <bits/stdc++.h>
using namespace std;
int fact(int n,int result)
{
    if (n==0) {
        cout<<result<<endl;
        return 0;
    }
    fact(n-1,result*n);
}

// Recursive approach to reverse an array
void swaps(int arr[],int left,int right){
    if(right<=left){
        return;
    }
    swap(arr[left],arr[right]);
    swaps(arr,left+1,right-1);
}

//Recusive function to generate all the subsequences of an array
void generates(int indx,vector<int>&v,int arr[],int n){
    if(indx==n){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back(arr[indx]);
    generates(indx+1,v,arr,n);
    v.pop_back();
    generates(indx+1,v,arr,n);
}



// Recursive function to check whether a given string is palindrome or not
bool check(string s,int slider){
    if(slider==s.size()/2)
    return true;
    if(s[slider]!=s[s.size()-1-slider])
    return false;

    return check(s,slider+1);
}
//Recursive function to print the subsequence whose sum equals to k

void printSubsequence(int indx,vector<int>&v,int s,int sum,int arr[],int n){
    if(indx==n){
        if(s==sum){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        }
        return;
    
    }
    v.push_back(arr[indx]);
    s+=arr[indx];
    printSubsequence(indx+1,v,s,sum,arr,n);
    v.pop_back();
    s-=arr[indx];
    printSubsequence(indx+1,v,s,sum,arr,n);
}
//Recursive function to print the subsequence whose sum equals to k(only one subsequence)

bool printOnlyOneSubsequence(int indx,vector<int>&v,int s,int sum,int arr[],int n){
    if(indx==n){
        if(s==sum){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        return true;
        }
        return false;
    }
    v.push_back(arr[indx]);
    s+=arr[indx];
    if(printOnlyOneSubsequence(indx+1,v,s,sum,arr,n)==true)
    return true;
    v.pop_back();
    s-=arr[indx];
    if(printOnlyOneSubsequence(indx+1,v,s,sum,arr,n)==true)
    return true;
    return false;
}
//Recursive function to count the number of subsequence
int countSubsequence(int indx,int s,int sum,int arr[],int n){
    if(indx==n){
        return (sum==s)?1:0;
 
    }
    s+=arr[indx];
    int left=countSubsequence(indx+1,s,sum,arr,n);
    s-=arr[indx];
    int right=countSubsequence(indx+1,s,sum,arr,n);
    return left+right;
}



int main()
{
    fact(5,1);
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    swaps(arr,0,5-1);
        for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
     int vec[]={3,1,2};
    vector<int> v;
    generates(0,v,vec,3);

    string s="madam";
    if(check(s,0))
    cout<<"The string is palindorme"<<endl;
    else
    cout<<"String is not palindrome";

    //Let k=2 and the array be {1,2,1} the subsequence whose sum is equal to k are {1,1} and {2}
    vector<int> subSeq;
    int valArr[]={1,2,1};
    printSubsequence(0,subSeq,0,2,valArr,3); //This will print all subsequences
    printOnlyOneSubsequence(0,subSeq,0,2,valArr,3);  //This will print only one subsequence
    int val=countSubsequence(0,0,2,valArr,3);  //Counts the number of subsequence
    cout<<val<<endl;

    return 0;
}