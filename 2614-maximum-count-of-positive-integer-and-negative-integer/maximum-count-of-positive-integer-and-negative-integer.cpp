class Solution {
public:
    int lb(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
    int maximumCount(vector<int>& nums) {
 
        int n = nums.size();
        int firstNonNeg = lb(nums, 0);
        int firstPos = lb(nums, 1);
        int neg = firstNonNeg;
        int pos = n - firstPos;
        return max(neg, pos);

        //int n = nums.size();
        //int left = 0;
        //int right = n - 1;
        //int firstNonNegative = n;
        //while(left <= right){
        //    int mid = left + (right - left) / 2;
        //    if(nums[mid] >= 0){
        //        firstNonNegative = mid;
        //        right = mid - 1;
//
        //    }
        //    else{
        //        left = mid + 1;
        //    }
        //}
        //int neg = firstNonNegative;
        //left = 0;
        //right = n - 1;
        //int firstPos = n;
        //while(left <= right){
        //    int mid = left + (right - left) / 2;
        //    if(nums[mid] > 0){
        //        firstPos = mid;
        //        right = mid - 1;
        //    }
        //    else{
        //        left = mid + 1;
//
        //    }
        //}
        //int pos = n - firstPos;
        //return max(pos, neg);
    }
};