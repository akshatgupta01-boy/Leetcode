class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans;
        for(int a : heights) ans.push_back(a);
        sort(ans.begin(), ans.end());
        int count = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i] != ans[i]) count++;
        }
        return count;
    }
};