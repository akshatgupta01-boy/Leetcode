class Solution {
public:
    bool checkString(string s) {
        // for(int i=0;i<s.length();i++){
        //     if(s[i] == 'a') continue;
        //     else if(s[i] == 'b'){
        //         for(int j=i;j<s.length();j++){
        //             if(s[j] == 'a') return false;
        //         }
        //     }
        // }
        // return true;

        return !s.contains("ba");
    }
};