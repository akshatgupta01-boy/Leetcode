class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> preSum(n);
        preSum[0] = nums[0];
        for(int i=1;i<n;i++){
            preSum[i] = preSum[i - 1] + nums[i];
        }
        int total = preSum[n - 1];
        for(int i=0;i<n;i++){
            int left = nums[i] * i - (i > 0 ? preSum[i-1] : 0);
            int right = (total - preSum[i]) - nums[i] * (n - i - 1);
            ans[i] = left + right;
        }
        return ans;
    }
};