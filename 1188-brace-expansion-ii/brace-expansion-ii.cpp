class Solution {
public:
    set<string> solve(string &s, int &i) {

        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = solve(s, i);

                i++; // skip '}'

                // Concatenate cur with inside
                set<string> temp;

                for (string a : cur) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                cur = temp;
            }

            else if (s[i] == ',') {
                // Union current part with the next part
                res.insert(cur.begin(), cur.end());

                cur = {""};
                i++;
            }

            else {
                // Normal character
                char ch = s[i];
                i++;

                set<string> temp;

                for (string x : cur) {
                    temp.insert(x + ch);
                }

                cur = temp;
            }
        }

        res.insert(cur.begin(), cur.end());

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};