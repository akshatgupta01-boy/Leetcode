class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        for(int i=0;;i++){
            long long x = pow(2, i);
            if(x == n) return true;
            else if(x > n) return false;
        }
    }
};