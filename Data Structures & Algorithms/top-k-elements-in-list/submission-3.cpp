class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);

        for(auto& [num, freq]: mp){
            buckets[freq].push_back(num);
        }


        vector<int> ans;
        for(int i = n ; i > 0 && ans.size() != k; i--){
            for (int j = 0; j < buckets[i].size(); j++){
                ans.push_back(buckets[i][j]);
                if(ans.size() == k){
                    break;
                }
            }
        }

        return ans;
    }
};
