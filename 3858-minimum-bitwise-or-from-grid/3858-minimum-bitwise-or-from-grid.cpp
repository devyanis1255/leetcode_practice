#include <vector>
using namespace std;
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size();
        int result = 0;
        // Iterate from MSB to LSB (assuming 31-bit integers)
        for (int bit = 30; bit >= 0; --bit) {
            // We want to see if we can achieve an OR sum 
            // that fits within this 'test_mask'
            int test_mask = result | ((1 << bit) - 1);
            bool possible = true;
            for (int i = 0; i < m; ++i) {
                bool row_ok = false;
                for (int val : grid[i]) {
                    // Check if 'val' only has bits that are set in 'test_mask'
                    // or in our already-fixed 'result' bits
                    if ((val | test_mask) == test_mask) {
                        row_ok = true;
                        break;
                    }
                }
                if (!row_ok) {
                    possible = false;
                    break;
                }
            }
            // If it's NOT possible to keep this bit 0, we must set it to 1
            if (!possible) {
                result |= (1 << bit);
            }
        }        
        return result;
    }
};