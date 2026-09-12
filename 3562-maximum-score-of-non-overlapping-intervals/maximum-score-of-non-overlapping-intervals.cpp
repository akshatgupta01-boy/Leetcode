class Solution {
public:
    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 4>> a;
        for(int i=0;i<n;i++){
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(), a.end());
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, 
        vector<pair<long long, vector<int>>> (5));
        for(int i=n - 1;i >= 0; i--){
            for(int k=1;k<=4;k++){
                dp[i][k] = dp[i + 1][k];   //dont take
                int left = i + 1, right = n;
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(a[mid][0] > a[i][1]) right = mid;
                    else left = mid + 1;
                }
                int next = left;
                long long score = a[i][2] + dp[next][k-1].first;
                vector<int> selected = dp[next][k-1].second;
                selected.push_back(a[i][3]);
                sort(selected.begin(), selected.end());
                vector<int> current = dp[i][k].second;
                sort(current.begin(), current.end());
                if(score > dp[i][k].first || score == dp[i][k].first && selected < current) dp[i][k] = {score, selected};
            }
        }
        return dp[0][4].second;
    }
};