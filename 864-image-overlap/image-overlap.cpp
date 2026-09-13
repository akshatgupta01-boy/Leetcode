class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> pos1;
        vector<pair<int, int>> pos2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1) pos1.push_back({i, j});
                if(img2[i][j] == 1) pos2.push_back({i, j});
            }
        }
        int ans = 0;
        map<pair<int, int>, int> mp;
        for(auto p1 : pos1){
            for(auto p2 : pos2){
                int row = p1.first - p2.first;
                int col = p1.second - p2.second;
                mp[{row, col}]++;
                ans = max(ans, mp[{row, col}]);
            }
        }
        return ans;
    }
};