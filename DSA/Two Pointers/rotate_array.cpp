//left rotate an array by one

/*
the optimal time complexity here will be O(n) and the space complexity will be O(1);
The approach is to store the first element of the array in a temporary variable and then shift all the elements of the array to the left by one position. Finally, we will place the stored element at the end of the array.
The space used in the array is O(n) because we are definitely using the given array to left rotate.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> leftrotate(vector<int> &nums){
  int temp =nums[0];
  int n =nums.size();
  for(int i =1;i<n;i++){
    nums[i-1]=nums[i];
  }
  nums[n - 1]= temp;
  return nums;
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  vector<int> ans =leftrotate(arr);
  for(int i =0;i<n;i++){
    cout<< ans[i] << " ";
  }
}