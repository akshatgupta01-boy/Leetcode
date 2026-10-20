class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);
        // Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }
        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        // Count decreases between adjacent elements
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i]);
        }
        auto check = [&](int k) {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int drops = prefDrop[end] - prefDrop[start];
                // Include the circular boundary
                if (nums[end] > nums[start]) drops++;
                if (drops > 1 || prefMax[start] > suffMin[start]) {
                    return false;
                }
            }
            return true;
        };
        int ans = 0;
        // Check only divisors of n
        for (int k = 1; k <= n / k; k++) {
            if (n % k == 0) {
                if (check(k)) ans += k;
                int other = n / k;
                if (other != k && check(other)) ans += other;
            }
        }
        return ans;
    }
};