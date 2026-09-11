class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[left] % 2 == 0) left++;
            else if(nums[right] % 2 != 0) right--;
            else{
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};