class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        
        for(int i=0;i<nums.size();i++){
            nums[i] *= nums[i];
            cout << nums[i] << ' ';
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            ans -= nums[i];
            ans += nums[j];
            i++;
            j--;
        }
        if(i == j) ans += nums[j];
        return ans;
    }
};