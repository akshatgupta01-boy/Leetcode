class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        map<pair<int, int>, int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1){
                    for(int x=0;x<n;x++){
                        for(int y=0;y<n;y++){
                            if(img2[x][y] == 1){
                                int row = i - x;
                                int col = j - y;
                                mp[{row, col}]++;
                                ans = max(ans, mp[{row, col}]);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};