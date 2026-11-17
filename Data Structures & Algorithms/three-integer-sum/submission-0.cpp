class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while(l < r){
                if(nums[l] + nums[r] == target){
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[l]);
                    triplet.push_back(nums[r]);
                    ans.push_back(triplet);
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                }
                else if(nums[l] + nums[r] > target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};
