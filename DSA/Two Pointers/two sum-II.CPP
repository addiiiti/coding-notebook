/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.
*/

/*
Concept / Pattern:
This problem uses the Two Pointer pattern on a sorted array.
One pointer starts from the beginning and the other from the end.
If the current sum is greater than the target, move the right pointer
left to decrease the sum. If the sum is smaller, move the left pointer
right to increase the sum. Since the array is sorted, this gives an
optimized linear solution instead of checking every pair.

Important Points:
- Array must be sorted.
- Question asks for 1-based indexing.
- Two pointers help reduce time complexity from O(n^2) to O(n).

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            long long sum = nums[left] + nums[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }

        return {};
    }
};

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<int> ans = obj.twoSum(nums, target);

    if (ans.size() > 0) {
        cout << "Indices are: ";
        for (int i : ans) {
            cout << i << " ";
        }
    }
    else {
        cout << "No valid pair found";
    }

    return 0;
}