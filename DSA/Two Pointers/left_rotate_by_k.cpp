//left rotate an array k places 
/*
the optimal time complexity here will be O(n) and the space complexity will be O(1);
The approach is to reverse the first k elements of the array, then reverse the remaining n-k elements and finally reverse the whole array. This way we can achieve the left rotation in O(n) time and O(1) space.
*/  
#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &nums, int start, int end){
  while(start < end){
    swap(nums[start], nums[end]);
    start++;
    end--;
  }
}
vector<int> leftrotate(vector<int> &nums, int k){
  int n = nums.size();
  k = k % n; // in case k is greater than n
  reverse(nums, 0, k - 1); // reverse first k elements
  reverse(nums, k, n - 1); // reverse remaining n-k elements
  reverse(nums, 0, n - 1); // reverse the whole array
  return nums;
}