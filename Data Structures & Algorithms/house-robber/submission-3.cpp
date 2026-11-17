class Solution
{
public:
    int houseRob(vector<int> &nums, vector<int> &dp, int i, int caller)
    {
        if (i > nums.size())
        {
            return 0;
        }
        if (i == nums.size())
        {
            if (caller == i - 1)
            {
                return 0;
            }
            return nums[i - 1];
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int ans = max(houseRob(nums, dp, i + 1, caller), houseRob(nums, dp, i + 2, caller) + nums[i]);
        dp[i] = ans;
        return ans;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return houseRob(nums, dp, 0, n - 1);
    }
};