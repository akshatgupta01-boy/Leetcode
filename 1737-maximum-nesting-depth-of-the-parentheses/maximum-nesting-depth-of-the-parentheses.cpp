class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count = 0;
        int ans = 0;
        for(char c : s){
            if(c == '('){
                st.push(c);
                count = st.size();
                ans = max(ans, count);
            }
            else if(c == ')'){
                st.pop();
            }
        }
        return ans;
    }
};