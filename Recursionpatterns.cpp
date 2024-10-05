
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
    cout<<"The string is palindorme";
    else
    cout<<"String is not palindrome";

    return 0;
}