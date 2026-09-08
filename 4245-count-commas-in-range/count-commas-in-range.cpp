class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        if(n < 1000) return 0;
        
        else count = n - 999;
        //else if(n < 100000) count = n - 9999;
        return count;
       
    }
};