class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i : nums) pq.push(i);
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        return (f - 1) * (s - 1);
    }
};