class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int left = 0, ones = 0;
        string ans = "";
        for(int right=0;right<n;right++){
            if(s[right] == '1') ones++;
            while(ones > k){
                if(s[left] == '1'){
                    ones--;

                }
                left++;
            }
            while(ones == k && s[left] == '0'){
                left++;
            }
            if(ones == k){
                string curr = s.substr(left, right - left + 1);
                if(ans.empty() || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)) ans = curr;
            }
        }
        return ans;
    }
};