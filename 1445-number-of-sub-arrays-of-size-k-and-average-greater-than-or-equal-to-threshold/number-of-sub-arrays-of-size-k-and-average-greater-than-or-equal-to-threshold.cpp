class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int total = 0;
        for(int i=0;i<k;i++){
            total += arr[i];
        }
        if(total / k >= threshold) count++;
        for(int i=k;i<arr.size();i++){
            total -= arr[i - k];
            total += arr[i];
            if(total / k >= threshold) count++;
        }
        return count;
    }
};