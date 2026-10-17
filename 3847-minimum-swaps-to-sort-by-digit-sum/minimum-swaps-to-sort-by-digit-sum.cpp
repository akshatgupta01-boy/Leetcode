class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<array<int, 3>> ans;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int digit = 0;
            while(num > 0){
                digit += num % 10;
                num /= 10;
            }
            ans.push_back({digit, nums[i], i});
        }
        sort(ans.begin(), ans.end());
        vector<bool> vis(nums.size(), false);
        int swaps = 0;
        for(int i=0;i<nums.size();i++){
            if(vis[i] || ans[i][2] == i) continue;
            int cycle = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = ans[j][2];
                cycle++;
            }
            if(cycle > 1) swaps += cycle - 1;
        }
        return swaps;
        
    }
};