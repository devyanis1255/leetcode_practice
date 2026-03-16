class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty array case

        int j = 0; // Pointer for the position of unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i]; // Move the unique element to the next position
            }
        }
        return j + 1; // Return the length of the array with unique elements
    }
};