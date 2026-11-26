class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        int an = 0;
        int k = 10;
        while(n >= k){
            n -= k;
            k--;
            an++;
        }
        if(an % 2 == 0) return false;
        return true;
    }
};