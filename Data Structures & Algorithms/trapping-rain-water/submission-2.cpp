class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1, maxL = height[l], maxR= height[r];

        int area = 0;
        while (l < r){
            if(maxR > maxL){
                l++;
                maxL = max(maxL, height[l]);
                area += maxL - height[l];
            }else{
                r--;
                maxR = max(maxR, height[r]);
                area += maxR - height[r];
            }
        }

        return area;
    }
};
