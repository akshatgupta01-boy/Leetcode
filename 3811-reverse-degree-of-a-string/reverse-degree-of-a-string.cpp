class Solution {
public:
    int reverseDegree(string s) {
        int num = 0;
        for(int i=0;i<s.length();i++){
            num += ('z' - s[i] + 1) * (i + 1);
        }
        return num;
    }
};