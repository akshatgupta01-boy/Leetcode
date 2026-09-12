class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Add original index
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // dp[i][k] = {score, original indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Don't take
                dp[i][k] = dp[i + 1][k];

                // Binary search next interval
                int l = i + 1, r = n;

                while (l < r) {
                    int mid = l + (r - l) / 2;

                    if (a[mid][0] > a[i][1])
                        r = mid;
                    else
                        l = mid + 1;
                }

                int next = l;

                // Take
                long long score =
                    a[i][2] + dp[next][k - 1].first;

                vector<int> selected =
                    dp[next][k - 1].second;

                selected.push_back(a[i][3]);

                sort(selected.begin(), selected.end());

                vector<int> current = dp[i][k].second;
                sort(current.begin(), current.end());

                if (score > dp[i][k].first ||
                    (score == dp[i][k].first &&
                     selected < current)) {

                    dp[i][k] = {score, selected};
                }
            }
        }

        return dp[0][4].second;
    }
};