class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<int> dp(k, 0);
        for(int num : nums){
            vector<int> newDp(k, 0);
            int rem = num % k;
            newDp[rem]++;
            for(int oldRem = 0; oldRem < k; oldRem++){
                int newRem = (1LL * oldRem * num) % k;
                newDp[newRem] += dp[oldRem]; 
            }
            dp = newDp;
            for(int i=0;i<k;i++){
                ans[i] += dp[i];
            }
        }
        return ans;
    }
};