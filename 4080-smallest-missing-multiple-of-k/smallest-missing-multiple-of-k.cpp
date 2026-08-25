class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int s : nums){
            st.insert(s);
        }
        for(int i=1;;i++){
            int mul = i * k;
            if(st.find(mul) == st.end()) return mul;
        }
        return -1;
    }
};