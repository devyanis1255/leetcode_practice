/*class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i=0 ; i<n ; ++i){
            ans[i] == nums[i];
           
        }
        for(int i=0 ; i<n ; ++i){
            ans[i+n] == nums[i];
        }
            
        return ans;
    }
};*/
class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(2 * n); 

        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
        }

        for (int i = 0; i < n; ++i) {
            ans[i + n] = nums[i]; 
        }

        return ans;
    }
};