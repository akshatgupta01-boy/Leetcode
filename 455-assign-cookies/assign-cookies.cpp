class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0;
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                ans++;
                i++;
                j++;
            }
            else if(s[j] < g[i]) j++;
        }
        // for(int i=0;i<g.size();i++){
        //     for(int j=0;j<s.size();j++){
        //         if(g[i] <= s[j]) ans++;
        //     }
        // }
        return ans;
    }
};