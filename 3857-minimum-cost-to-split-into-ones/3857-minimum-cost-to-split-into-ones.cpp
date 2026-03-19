class Solution {
public:
    int minCost(int n) {
        // The minimum cost is always the sum of 1 to (n-1)
        // Using long long to prevent overflow for larger values of n
        return (long long)(n - 1) * n / 2;
    }
};