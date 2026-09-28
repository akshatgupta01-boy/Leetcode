class Solution {
public:
    int maximumSwap(int num) {
        string a = to_string(num);
        vector<int> last(10, -1);
        for(int i=0;i<a.length();i++){
            last[a[i] - '0'] = i;
        }
        for(int i=0;i<a.length();i++){
            for(int d=9;d > a[i] - '0';d--){
                if(last[d] > i){
                    swap(a[i], a[last[d]]);
                    return stoi(a);
                }
            }
        }
        return num;
    }
};