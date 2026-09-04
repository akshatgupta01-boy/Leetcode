class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int f = INT_MIN;
            int s = INT_MAX;
            for(int j = 0; j <= i; j++){
                f = max(f, nums[j]);
            }
            for(int j=i;j<n;j++){
                s = min(s, nums[j]);
            }
            if(f - s <= k) return i;
        }
        return -1;
    }
};