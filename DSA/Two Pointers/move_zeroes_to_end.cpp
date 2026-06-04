//move zeroes to end of the array

//brute force solution
/*
take a temp array and put the non-zeroes elements in it
vector<int> temp;
for(int i =0;i<nums.size();i++){
  if(nums[i] != 0){
    temp.push_back(nums[i]);
  }
}
then fill the original array with the elements of temp and fill the remaining elements with zeroes
for(int i =0;i<temp.size();i++){
  nums[i] = temp[i];
}
fill remaining elements with zeroes
for(int i = temp.size();i<nums.size();i++){
  nums[i] = 0;
} 
*/

/*
Optimal Approach (Two Pointers):
Find the first zero and store its index in j. Then traverse the remaining array with i; whenever a non-zero element is found, swap nums[i] with nums[j] and increment j.
This keeps all non-zero elements in their relative order while pushing zeroes towards the end in a single traversal.
*/
#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
  int j =-1;
  for(int i =0;i<nums.size();i++){
    if(nums[i] == 0){
      j=i;
      break;
    }
  }
  if(j == -1){
    return; // no zeroes found
  }
  for(int i = j+1;i<nums.size();i++){
    if(nums[i] != 0){
      swap(nums[i], nums[j]);
      j++;
    }
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i =0;i<n;i++){
    cin >> nums[i];
  }
  moveZeroes(nums);
  for(int i =0;i<n;i++){
    cout << nums[i] << " ";
  }
}
