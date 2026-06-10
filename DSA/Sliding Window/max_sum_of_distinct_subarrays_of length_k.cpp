// Max Sum of Distinct Subarrays of Length K
/*Sliding Window + Frequency Map

Goal:
Maintain the minimum information needed to determine if the window is valid.

State:
1. window_sum
2. frequency map
3. unique_count

Important frequency transitions:

Insertion:
0 -> 1 : unique_count++
1 -> 2 : no change
2 -> 3 : no change

Deletion:
1 -> 0 : unique_count--
2 -> 1 : no change
3 -> 2 : no change

Window validity:
unique_count == k

Key Insight:
Do not recheck the entire window.
When the window slides, only two frequencies change:
- outgoing element
- incoming element

Update state using only these two changes.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        long long windowsum = 0;
        int unique_count = 0;
        long long ans = 0;// if unique_count==k, max of all the distinct subarrays' sum will become the ans;
        for(int i =0;i<k;i++){
            windowsum += nums[i];
            freq[nums[i]]++;
            if(freq[nums[i]]==1){
                unique_count++;
            }
        }
        if(unique_count == k){
            ans=windowsum;
        }
        //slide the window
        for(int i = k;i< n; i++){
            int outgoing = nums[i-k];
            int incoming = nums[i];
            windowsum -= outgoing;
            freq[outgoing]--;
            if(freq[outgoing] == 0){
                unique_count--;
            }
            windowsum += incoming;
            freq[incoming]++;
            if(freq[incoming] == 1){
                unique_count++;
            }
            if(unique_count ==k){
                ans = max(ans,windowsum);
            }
        }
        return ans;
       
    }
    int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum sum of distinct subarray of size "
         << k << " = "
         << maximumSubarraySum(nums, k)
         << endl;

    return 0;
}