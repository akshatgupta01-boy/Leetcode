class Solution {
public:
    int reverseDegree(string s) {
        int num = 0;
        for(int i=1;i<=s.length();i++){
            num += ('z' - s[i-1] + 1) * i;
        }
        return num;
    }
};