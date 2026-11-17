class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int maxAns = 0;
        while(l < r){
            int curr = (r - l) * min(heights[l], heights[r]);
            maxAns = max(maxAns, curr);
            if(heights[l] > heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxAns;
    }
};
