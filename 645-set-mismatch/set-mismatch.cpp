class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup = 0;
        int mis = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) dup = nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            if(!binary_search(nums.begin(), nums.end(), i)) mis = i;
        }
        return {dup, mis};
    }
};