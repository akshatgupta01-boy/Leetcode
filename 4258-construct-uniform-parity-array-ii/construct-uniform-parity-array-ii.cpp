class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int s = INT_MAX, t = INT_MAX;
        for(int num : nums1){
            if(num % 2 == 0){
                s = min(s, num);
            }
            else{
                t = min(t, num);
            }
        }
        return (t == INT_MAX) || t < s;
    }
};