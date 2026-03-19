#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        long long totalCount = 0;   
        // We need to find the number of subarrays where:
        // 1. Distinct elements == k
        // 2. Each of those k elements freq >= m       
        unordered_map<int, int> count1, count2;
        int distinct1 = 0, satisfied1 = 0; // For the "at least m" boundary
        int distinct2 = 0;                 // For the "k distinct" boundary
        int left = 0, mid = 0;
        for (int right = 0; right < n; ++right) {
            // Update the window for the 'mid' pointer (Condition 1 & 2)
            if (++count1[nums[right]] == 1) distinct1++;
            if (count1[nums[right]] == m) satisfied1++;
            // Update the window for the 'left' pointer (Condition 1 only)
            if (++count2[nums[right]] == 1) distinct2++;
            // Shrink 'left' to maintain exactly k or k-1 distinct
            while (distinct2 > k) {
                if (--count2[nums[left]] == 0) distinct2--;
                left++;
            }
            // Shrink 'mid' while it still satisfies both conditions
            // We want 'mid' to be the rightmost possible start of a valid subarray
            while (distinct1 > k || (distinct1 == k && satisfied1 == k)) {
                if (count1[nums[mid]] == m) satisfied1--;
                if (--count1[nums[mid]] == 0) distinct1--;
                mid++;
            }            
            // Any start index in the range [left, mid-1] is valid 
            // IF the current window [mid-1, right] was valid.
            if (distinct2 == k) {
                totalCount += (mid - left);
            }
        }
        return totalCount;
    }
};