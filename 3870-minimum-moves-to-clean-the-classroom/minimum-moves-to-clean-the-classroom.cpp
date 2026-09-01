class Solution {
public:
    int minMoves(vector<string>& a, int E) {
        int m = a.size(), n = a[0].size();
        int sr, sc, k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                if(a[i][j]=='S') sr=i, sc=j;
                if(a[i][j]=='L') id[i][j]=k++;
            }

        if(k == 0) return 0;

        int full = (1<<k)-1;
        int N = m*n*(E+1)*(1<<k);

        vector<char> vis(N);
        queue<array<int,4>> q;

        q.push({sr,sc,E,0});

        auto code = [&](int r,int c,int e,int mask) {
            return ((((r*n+c)*(E+1)+e)<<k)|mask);
        };

        vis[code(sr,sc,E,0)] = 1;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r,c,e,mask] = q.front();
                q.pop();

                if(mask == full) return ans;
                if(e == 0) continue;

                for(int d=0;d<4;d++) {
                    int x=r+dr[d], y=c+dc[d];

                    if(x<0 || x>=m || y<0 || y>=n || a[x][y]=='X')
                        continue;

                    int ne=e-1, nm=mask;

                    if(a[x][y]=='L')
                        nm |= 1<<id[x][y];

                    if(a[x][y]=='R')
                        ne=E;

                    int s=code(x,y,ne,nm);

                    if(!vis[s]) {
                        vis[s]=1;
                        q.push({x,y,ne,nm});
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};