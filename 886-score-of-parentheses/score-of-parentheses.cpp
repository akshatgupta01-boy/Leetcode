class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') depth++;
            else if(s[i] == ')'){
                depth--;
                if(s[i-1] == '('){
                    score += pow(2, depth);
                }
            } 
        }
        return score;
    }
};