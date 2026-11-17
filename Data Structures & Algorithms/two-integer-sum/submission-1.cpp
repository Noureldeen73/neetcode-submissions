class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> order;
        for(int i = 0; i < nums.size(); i++)
        {
            order[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = order.find(target - nums[i]);
            int index = (*it).second;
            if(it != order.end() && index != i)
            {
                vector<int> ans {min(index, i), max(index, i)};
                return ans;
            }
        }
        
    }
};
