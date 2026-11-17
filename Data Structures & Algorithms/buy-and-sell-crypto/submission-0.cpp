class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minVal = prices[0];
        for(int i = 1; i < prices.size(); i++){
             ans = max(ans, prices[i] - minVal);
            if(prices[i] < minVal){
                minVal = prices[i];
            }
        }
        return ans;
    }
};
