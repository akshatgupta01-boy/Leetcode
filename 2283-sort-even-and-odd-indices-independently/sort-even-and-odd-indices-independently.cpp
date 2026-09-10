class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<nums.size();i++){
            if(i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        vector<int> ans(n);
        int e = 0;
        int o = 0;
        for(int i=0;i<nums.size();i++){
            if(i % 2 == 0)
                ans[i] = even[e++];
            else
                ans[i] = odd[o++];
        }
        return ans;
    }
};