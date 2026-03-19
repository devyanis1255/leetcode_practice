#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) if (c == '0') initial_zeros++;
        if (initial_zeros == 0) return 0;
        // Separate sets for even and odd zero counts that are still unvisited
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }
        queue<pair<int, int>> q;
        q.push({initial_zeros, 0});
        unvisited[initial_zeros % 2].erase(initial_zeros);

        while (!q.empty()) {
            auto [curr_z, steps] = q.front();
            q.pop();
            // Range calculation
            int min_j = max(0, k - (n - curr_z));
            int max_j = min(curr_z, k);
            int left = curr_z + k - 2 * max_j;
            int right = curr_z + k - 2 * min_j;
            int parity = left % 2;
            auto& s_set = unvisited[parity];
            // Use lower_bound to find the first unvisited number >= left
            auto it = s_set.lower_bound(left);
            while (it != s_set.end() && *it <= right) {
                int next_z = *it;
                if (next_z == 0) return steps + 1;        
                q.push({next_z, steps + 1});
                // Erase returns the next iterator, allowing O(n) total deletions
                it = s_set.erase(it);
            }
        }
        return -1;
    }
};