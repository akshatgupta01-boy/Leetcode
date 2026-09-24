class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == i && nums[i] < 10) return i;
            int rem = nums[i];
            int digit = 0;
            if(rem > 9){
                while(rem > 0){
                digit += rem % 10;
                rem /= 10;
                }
                if(digit == i) return i;
            }
            
            
        }
        return -1;
    }
};