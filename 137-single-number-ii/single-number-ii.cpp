class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(int num : nums){
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};