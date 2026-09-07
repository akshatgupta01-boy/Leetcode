class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        int n = s.length();
        vector<vector<long long>> dp(n + 1, vector<long long> (26, 0));
        for(int i=1;i<=n;i++){
            int curr = s[i - 1] - 'a';
            long long total = 0;
            for(int j=0;j<26;j++) total = (total + dp[i-1][j]) % mod;
            for(int j=0;j<26;j++) dp[i][j] = dp[i-1][j];
            dp[i][curr] = (total + 1) % mod;
        }
        long long ans = 0;
        for(int j=0;j<26;j++){
            ans = (ans + dp[n][j]) % mod;
        }
        return ans;
    }
};