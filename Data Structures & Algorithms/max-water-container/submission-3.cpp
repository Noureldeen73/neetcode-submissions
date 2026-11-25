class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int ans = 0;
        int l = 0, r = n - 1;

        while (l < r){
            int area = (r - l) * min(heights[l], heights[r]);
            ans = max(ans, area);

            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }
};
