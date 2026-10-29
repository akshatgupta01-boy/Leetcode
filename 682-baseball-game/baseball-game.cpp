class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(int i=0;i<operations.size();i++){
            if(operations[i] != "C" && operations[i] != "D" && operations[i] != "+"){
                ans.push_back(stoi(operations[i]));
            }
            else if(operations[i] == "C") ans.pop_back();
            else if(operations[i] == "D") ans.push_back(ans.back() * 2);
            else if(operations[i] == "+"){
                int last = ans.back();
                int slast = ans[ans.size()-2];
                ans.push_back(last + slast);
            } 
        } 
        int res = 0;
        for(int i=0;i<ans.size();i++){
            res += ans[i];
        }
        return res;
    }
};