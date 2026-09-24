class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : prices) pq.push(i);
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int ans = a + b;
        if(ans <= money) return money - ans;
        return money;



        // sort(prices.begin(), prices.end());
        // int ans = prices[0] + prices[1];
        // if(ans <= money) return money - ans;
        // return money;
    }
};