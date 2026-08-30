class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        int mins = 0;
        int maxs = 0;
        for(int i=1;i<n;i++){
            if(mini > nums[i]){
                mini = nums[i];
                mins = i;
            }
            if(maxi < nums[i]){
                maxi = nums[i];
                maxs = i;
            }
        }
        if(mins > maxs) swap(mins, maxs);
        int left = maxs + 1;
        int right = n - mins;
        int both = (mins + 1) + (n - maxs);
        return min({left, right, both});
    }
};