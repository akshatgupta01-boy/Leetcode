class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        while(left < right){
            int mid = left + (right - left) / 2;
            int parts = 1;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                if(sum + nums[i] > mid){
                    parts++;
                    sum = nums[i];
                }
                else{
                    sum += nums[i];
                }
            }
            if(parts <= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};