//right rotate an array by k
/*
the optimal time complexity here will be O(n) and the space complexity will be O(1);
The approach is to reverse the n-k elements, then reverse the k elements and finally reverse the entire array. This way we can achieve the right rotation in O(n) time and O(1) space.
*/
#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rightRotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // In case k is greater than n
    reverse(arr, 0, n - k - 1); // Reverse the first n-k elements
    reverse(arr, n - k, n - 1); // Reverse the last k elements
    reverse(arr, 0, n - 1); // Reverse the entire array
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
      cin >> arr[i];
    }
  
    rightRotate(arr, k);
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}