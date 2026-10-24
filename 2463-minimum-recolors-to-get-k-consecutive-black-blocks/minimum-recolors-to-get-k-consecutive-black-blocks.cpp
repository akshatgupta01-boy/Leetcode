class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        for(int i=0;i<k;i++){
            if(blocks[i] == 'W') count++;
        }
        int minCount = count;
        for(int i=k;i<blocks.length();i++){
            if(blocks[i - k] == 'W') count--;
            if(blocks[i] == 'W') count++;
            minCount = min(minCount, count);
        }
        return minCount;
    }
};