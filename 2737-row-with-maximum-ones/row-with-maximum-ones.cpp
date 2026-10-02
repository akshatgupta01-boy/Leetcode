class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int index = 0;
        for(int i=0;i<mat.size();i++){
            int ones = 0;
            for(int a : mat[i]){
                ones += a;
            }
            if(ones > maxOnes){
                maxOnes = ones;
                index = i;
            }
        }
        return {index, maxOnes};
    }
};