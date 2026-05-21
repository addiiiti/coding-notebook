/*
Sort an array of 0s, 1s and 2s in linear time and using constant space. This problem is also known as the Dutch National Flag problem.
in leetcode , it is given as sort colors

*/
/* 
solution
Dutch National Flag Algorithm:
Used for in-place partitioning problems where array elements belong to limited categories like 0/1/2, even/odd, negative/positive, etc.

Important Points:
Works in O(n) time and O(1) space using 3 pointers (low, mid, high) while maintaining left, middle, and right regions dynamically.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low =0;
       int mid =0;
       int high =nums.size()-1;
       while(mid<=high){
          if (nums[mid]==0){
          swap(nums[low],nums[mid]);
          low++;
          mid++;
          }
          else if(nums[mid]==1){
            mid++;
            }
            else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
          }
        }
    }
};
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution obj;
    obj.sortColors(nums);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
  }

