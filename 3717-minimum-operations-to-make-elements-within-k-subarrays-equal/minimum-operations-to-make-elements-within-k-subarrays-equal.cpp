class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> left, right;
        long long sumL = 0, sumR = 0;
        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;
                right.insert(v);
                sumR += v;
            }
            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;
                left.insert(v);
                sumL += v;
            }
        };
        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
            balance();
        };
        auto remove = [&](int v) {
            auto it = left.find(v);
            if (it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                right.erase(right.find(v));
                sumR -= v;
            }
            balance();
        };
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long med = *left.rbegin();
                cost[i - x + 1] = med * left.size() - sumL +
                    sumR - med * right.size();
            }
        }
        const long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF)
        );
        dp[0][0] = 0;
        for (int j = 0; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (j > 0 && i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }
        return dp[k][n];
    }
};