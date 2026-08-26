class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int l, int r){
        if(l == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int k=l;k<r;k++){
            int left = prefix[k + 1] - prefix[l];
            int right = prefix[r + 1] - prefix[k + 1];

            if(left < right){
                ans = max(ans, left + solve(nums, l, k));
            }
            else if(right < left){
                ans = max(ans, right + solve(nums, k + 1, r));
            }
            else{
                ans = max(ans, left + max(solve(nums, l, k), solve(nums, k + 1, r)));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        prefix.resize(n + 1, 0);
        for(int i=0;i<n;i++){
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }   
        dp.assign(n, vector<int>(n , -1));
        return solve(stoneValue, 0, n - 1);
    }
};