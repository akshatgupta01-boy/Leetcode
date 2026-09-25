class Solution {
public:
    set<string> solve(string &exp, int &i){
        set<string> res;
        set<string> curr = {""};
        while(i < exp.size() && exp[i] != '}'){
            if(exp[i] == '{'){
                i++;
                set<string> inside = solve(exp, i);
                i++;
                set<string> temp;
                for(string a : curr){
                    for(string b : inside){
                        temp.insert(a + b);
                    }
                } 
                curr = temp;
            }
            else if(exp[i] == ','){
                res.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }
            else{
                char ch = exp[i];
                i++;
                set<string> temp;
                for(string a : curr){
                    temp.insert(a + ch);
                }
                curr = temp;
            }
        }
        res.insert(curr.begin(), curr.end());
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = solve(expression, i);
        return vector<string> (res.begin(), res.end());
    }
};