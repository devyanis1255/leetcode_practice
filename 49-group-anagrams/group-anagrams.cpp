class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        vector<string> dup = strs;

        for(int i = 0; i< strs.size(); i++){
            sort(dup[i].begin(), dup[i].end());
            mp[dup[i]].push_back(i);
        }
        vector<vector<string>> ans;

        for(auto &[key, v] : mp){
            ans.push_back({});
            for(auto idx : v){
                ans.back().push_back(strs[idx]);
            }
        }
        return ans;
    }
};