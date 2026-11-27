class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> dp(budget + 1, 0);
        int mn = INT_MAX;
        for(auto &i : items){
            int factor = i[0];
            int price = i[1];
            mn = min(mn, price);
            int cnt = 0;
            for(auto &j : items){
                if(j[0] % factor == 0) cnt++;
            }
            for(int j=budget; j>= price; j--){
                dp[j] = max(dp[j], dp[j - price] + cnt);
            }
        }
        int ans = 0;
        for(int i=0;i<=budget;i++){
            ans = max(ans, dp[i] + (budget - i) / mn);
        }
        return ans;
    }
};