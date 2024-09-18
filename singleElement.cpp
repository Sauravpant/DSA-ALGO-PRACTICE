/*
SINGLE ELEMENT IN SORTED ARRAY
Problem statement:
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which
appears exactly once. Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
Approach
There are only two possible cases:

1. The mid index is even
If mid index is even then the elements upto its last index must be paired for the left half to not contain duplicate . So we check if the value 
at that index and the next index after it are equal if so, it means the left half doesnt contain any duplicate so we adjust pointers to check in 
right half as low=mid+2 (we skip the mid and mid+1index as they are equal ) else if the value at that index and index after that doesnt have same
value then it means that the duplicate is in left half so we adjust high pointer as high=mid and continue again.

2.The mid index is odd
-If the mid index is odd, then we need to check the element at the mid index and the element just before it ( mid - 1). If they are equal, it means
 the left half up to mid - 1 does not contain the single element, and the duplicate element is in the right half, so we adjust our pointers to 
 search in the right half: low = mid + 1. Otherwise, if the element at mid and mid - 1 are not equal, it indicates that the single element m must 
be in the left half, so we adjust the high pointer as high = mid - 1 and continue searching in the left half.

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    low=mid+2;
                }
                else
                high=mid;
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else
                high=mid;
            }
        }
        return nums[low];
        
    }
};