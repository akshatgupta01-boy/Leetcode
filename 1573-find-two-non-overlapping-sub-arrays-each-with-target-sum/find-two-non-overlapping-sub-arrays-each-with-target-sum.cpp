class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        // best[i] = shortest valid subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int answer = INT_MAX;

        for(int right = 0; right < n; right++) {

            sum += arr[right];

            while(sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry previous shortest length
            if(right > 0)
                best[right] = best[right - 1];

            // Found a subarray
            if(sum == target) {

                int len = right - left + 1;

                // Find another subarray BEFORE this one
                if(left > 0 && best[left - 1] != INT_MAX) {

                    answer = min(
                        answer,
                        len + best[left - 1]
                    );
                }

                // Store current subarray if it is shorter
                best[right] = min(best[right], len);
            }
        }

        if(answer == INT_MAX)
            return -1;

        return answer;
    }
};