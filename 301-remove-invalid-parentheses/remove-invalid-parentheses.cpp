class Solution {
public:
    unordered_set<string> st;

    void solve(string &s, int index, int leftRemove, int rightRemove, int open, string curr) {
        if (index == s.length()) {
            if (leftRemove == 0 && rightRemove == 0 && open == 0) {
                st.insert(curr);
            }
            return;
        }

        char c = s[index];

        // Remove '('
        if (c == '(' && leftRemove > 0) {
            solve(s, index + 1, leftRemove - 1,
                  rightRemove, open, curr);
        }

        // Remove ')'
        if (c == ')' && rightRemove > 0) {
            solve(s, index + 1, leftRemove,
                  rightRemove - 1, open, curr);
        }

        // Keep current character
        if (c != '(' && c != ')') {
            solve(s, index + 1, leftRemove,
                  rightRemove, open, curr + c);
        }
        else if (c == '(') {
            solve(s, index + 1, leftRemove,
                  rightRemove, open + 1, curr + c);
        }
        else if (open > 0) {
            solve(s, index + 1, leftRemove,
                  rightRemove, open - 1, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        solve(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(st.begin(), st.end());
    }
};