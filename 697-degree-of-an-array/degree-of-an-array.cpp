class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> first, last, freq;
        int degree = 0;
        int ans = n;
        for(int i=0;i<n;i++){
            if(first.find(nums[i]) == first.end()) first[nums[i]] = i;
            last[nums[i]] = i;
            freq[nums[i]]++;
            degree = max(degree, freq[nums[i]]);
        }
        for(auto x : freq){
            if(x.second == degree){
                int num = x.first;
                ans = min(ans, last[num] - first[num] + 1);
            }
        }
        return ans;
    }
};