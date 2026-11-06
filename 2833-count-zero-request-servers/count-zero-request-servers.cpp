class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
         int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });
        vector<pair<int,int>> q;
        for (int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<int> ans(queries.size());
        unordered_map<int,int> cnt;
        int left = 0, right = 0, active = 0;
        for (auto [time, idx] : q) {
            // Add logs up to current query time
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];
                if (cnt[server] == 0) active++;
                cnt[server]++;
                right++;
            }
            // Remove logs outside the time window
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];
                cnt[server]--;
                if (cnt[server] == 0) active--;
                left++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};
