class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string temp = "";
            for(int i=0;i<s.length();i+=k){
                int ans = 0;
                for(int j=i;j<min((int)s.length(), i+k);j++){
                    ans += s[j] - '0';
                }
                temp += to_string(ans);
            }
            s = temp;
        }
        return s;
    }
};