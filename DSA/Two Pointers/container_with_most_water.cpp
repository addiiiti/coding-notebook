// Container With Most Water
/*
Brute Force operation would take O(n^2) time complexity, we can optimize it using two pointers approach. We can start with two pointers at the beginning and end of the array, and calculate the area formed by the lines at these two pointers. We can then move the pointer that has the smaller height towards the other pointer, in order to try to find a larger area. We repeat this process until the two pointers meet. This approach takes O(n) time complexity, as we are only traversing the array once.
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxWater = max(maxWater, h * w);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
      cin >> arr[i];
  }
  cout << "Maximum area of water that can be contained: " << maxArea(arr) << endl;
  return 0;
}
