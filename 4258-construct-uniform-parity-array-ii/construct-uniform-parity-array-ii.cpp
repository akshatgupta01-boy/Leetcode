class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int s = INT_MAX, t = INT_MAX;
        for(int m : nums1){
            if(m % 2 == 0){
                s = min(s, m);
            }
            else{
                t = min(t, m);
            }
        }
        return (t == INT_MAX) ||  t < s;
    }
};