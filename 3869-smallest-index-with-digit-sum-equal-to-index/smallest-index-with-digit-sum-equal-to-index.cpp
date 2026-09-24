class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int digit = 0;
            while(num > 0){
                digit += num % 10;
                num /= 10;
            }
            if(digit == i) return i;
        }
        return -1;
    }
};