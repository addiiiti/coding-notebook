/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/


/*
Concept / Pattern:
This problem follows the Sorting + Two Pointer pattern.
First, we sort the array so that we can efficiently use
two pointers to find pairs along with one fixed element.

For every index i:
- nums[i] is fixed.
- j starts from i+1.
- k starts from the end.
- If sum > 0, decrease k to reduce the sum.
- If sum < 0, increase j to increase the sum.
- If sum == 0, store the triplet.

Important Part:
We skip duplicates for:
1. i -> to avoid repeating same starting element.
2. j -> to avoid same middle element triplets.
3. k -> to avoid same ending element triplets.

This ensures unique triplets only.

Time Complexity: O(n^2)
- Outer loop runs n times.
- Two pointers together run O(n).

Space Complexity: O(1)
- Ignoring output array.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate j
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate k
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<vector<int>> ans = obj.threeSum(nums);

    if (ans.size() == 0) {
        cout << "No triplets found";
    }
    else {

        cout << "Triplets are:\n";

        for (auto triplet : ans) {

            cout << "[ ";

            for (int num : triplet) {
                cout << num << " ";
            }

            cout << "]\n";
        }
    }

    return 0;
}