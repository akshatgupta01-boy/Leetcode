class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0];
        int maxVal = nums[0];
        int minInd = 0;
        int maxInd = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < minVal){
                minVal = nums[i];
                minInd = i;
            }
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxInd = i;
            }
        }
        if(minInd > maxInd) swap(minInd, maxInd);
        int left = maxInd + 1;
        int right = n - minInd;
        int both = (minInd + 1) + (n - maxInd);
        return min({left, right, both});
    }
};