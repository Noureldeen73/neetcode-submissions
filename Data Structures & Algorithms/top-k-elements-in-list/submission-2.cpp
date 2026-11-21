class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto& num: nums){
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto& [number, frequency] : freq){
            bucket[frequency].push_back(number);
        }
        vector<int> res;

        for(int i = nums.size(); i >0; i--){
            if(bucket[i].size() == 0) continue;

            for(int j = 0; j < bucket[i].size(); j++){
                res.push_back(bucket[i][j]);
                if(res.size() == k){
                    return res;
                }
            }
        }

        return res;
    }
};
