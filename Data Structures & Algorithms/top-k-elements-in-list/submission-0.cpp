class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto p: freq)
        {
            pq.emplace(p.second, p.first);
        }      
        vector<int> ans;
        while(k--)
        {
            auto [_, num] = pq.top();
            pq.pop();
            ans.push_back(num);
        }         
        return ans;
    }
};
