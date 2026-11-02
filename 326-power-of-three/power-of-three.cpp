class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        for(int i=0;;i++){
            long long sum = pow(3, i);
            if(sum == n) return true;
            else if(sum > n) return false;
        }
    }
};