class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        vector<int> dp2(n + 1, 0);
        if(n < 2){
            return nums[0];
        }
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        dp2[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        }
        return max(dp[n - 1], dp2[n]);
    }
};