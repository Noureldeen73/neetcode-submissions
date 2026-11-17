class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = true;
        }
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i] - 1]){
                continue;
            }
            int len = 0;
            int curr = nums[i];
            while(mp[curr]){
                len++;
                curr++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
