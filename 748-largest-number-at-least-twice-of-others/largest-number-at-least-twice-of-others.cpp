class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
        }
        if(pq.size() > 1){
            auto f = pq.top();
            pq.pop();
            auto s = pq.top();
            pq.pop();

            if(f.first >= (s.first * 2)) return f.second;
        }
        return -1;
    }
};