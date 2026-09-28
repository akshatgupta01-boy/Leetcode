class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        vector<int> last(10, -1);
        for(int i=0;i<nums.size();i++){
            last[nums[i] - '0'] = i;
        }
        for(int i=0;i<nums.size();i++){
            for(int d = 9; d > nums[i] - '0'; d--){
                if(last[d] > i){
                    swap(nums[i], nums[last[d]]);
                    return stoi(nums);
                }
            }
        }
        return num;
    }
};