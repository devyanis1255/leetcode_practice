class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int total = 0;

        for(int i : nums){
            if(total <  0){
                total = 0;
            }
            total += i;
            result = max(result, total);
        }
        return result;
    }
};