class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for (auto& x : s){
            if (s.contains(x - 1)) continue;
            int length = 1;
            int j = x + 1;
            while(s.contains(j)){
                length++;
                j++;
            }
            ans = max(ans, length);
        }

        return ans;
    }
};
