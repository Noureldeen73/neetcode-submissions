class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mono;
        int n = temperatures.size();
        vector<int> result(n);
        for(int i = n - 1; i >= 0; --i){
            while(!mono.empty() && mono.top().first <= temperatures[i]){
                mono.pop();
            }
            if(mono.empty()) result[i] = 0;
            else result[i] = mono.top().second;
            mono.push({temperatures[i], i});
        }
        for(int i = 0; i < n; i++){
            if(result[i] == 0) continue;
            result[i] -= i;
        }
        return result;
    }
};
