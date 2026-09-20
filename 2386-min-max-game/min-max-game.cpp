class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size() > 1){
            vector<int> ans;
            for(int i=0;i<nums.size();i+=2){
                if(ans.size() % 2 == 0){
                    ans.push_back(min(nums[i], nums[i + 1]));
                }else{
                    ans.push_back(max(nums[i], nums[i + 1]));
                }
            }
            nums = ans;
        }
        return nums[0];
    }
};