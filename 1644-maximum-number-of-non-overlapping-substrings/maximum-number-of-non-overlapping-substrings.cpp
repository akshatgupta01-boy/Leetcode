class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for(int i=0;i<n;i++){
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> interval;
        for(int c=0;c<26;c++){
            if(last[c] == -1) continue;
            int l = first[c];
            int r = last[c];
            bool valid = true;

            for(int i=l;i<=r;i++){
                int x = s[i] - 'a';
                if(first[x] < l){
                    valid = false;
                    break;
                }
                r = max(r, last[x]);
            } 
            if(valid) interval.push_back({l, r});
        }
        sort(interval.begin(), interval.end(), [](auto &a, auto &b){ return a.second < b.second;});
        vector<string> ans;
        int end = -1;
        for(auto[l, r] : interval){
            if(l > end){
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }
        return ans;
    }
};