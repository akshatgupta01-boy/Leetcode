class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        ans[n - 1] = nums[n - 1];
        for(int i=n-2;i>=0;i--){
            ans[i] = min(nums[i], ans[i + 1]);
        }
        int left = 0;
        for(int i=0;i<n;i++){
            left = max(left, nums[i]);
            if(left - ans[i] <= k) return i;
        }
        return -1;
    }
};