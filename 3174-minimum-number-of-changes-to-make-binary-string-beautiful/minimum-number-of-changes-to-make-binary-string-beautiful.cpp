class Solution {
public:
    int minChanges(string s) {
        if(s.length() % 2 != 0) return 0;
        int count = 0;

        for(int i=0;i<s.length();i+=2){
            if(s[i] != s[i + 1]) count++;
        }
        
        // int zero = 0;
        // int one = 0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i] == '1') one++;
        //     else zero++;
        // }
        // if(one > zero){
        //     for(int i=0;i<s.length();i++){
        //         if(s[i] == '0') count++;
        //     }
        // }
        // if(one <= zero){
        //     for(int i=0;i<s.length();i++){
        //         if(s[i] == '1') count++;
        //     }
        // }
        return count;
    }
};