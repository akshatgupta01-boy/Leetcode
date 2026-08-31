class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        for(int i=0;;i++){
            long long x = pow(4, i);
            if(n == x) return true;
            else if(x > n) return false; 
        }
    }
};