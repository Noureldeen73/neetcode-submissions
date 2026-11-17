class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> mono;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int start = i;
            while(!mono.empty() && heights[i] < mono.top().second){
                auto p = mono.top();
                mono.pop();
                maxArea = max(maxArea, p.second * (i - p.first));
                start = p.first;
            }
            mono.push({start, heights[i]});
        }
        while(!mono.empty()){
            auto p = mono.top();
            mono.pop();
            maxArea = max(maxArea, p.second * (n - p.first));
        }
        return maxArea;
    }
};
