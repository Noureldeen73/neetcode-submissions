class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     int n = nums.size();

     sort(nums.begin(), nums.end());

     vector<vector<int>> ans;

     for (int i = 0; i < n; i++){
        if(nums[i] > 0){
            break;
        }
        if(i - 1 >= 0 && nums[i] == nums[i - 1]) continue;
        int target = -nums[i], l = i + 1, r = n - 1;

        while (l < r){
            int sum = nums[l] + nums[r];
            if(sum < target){
                l++;
            }else if (sum > target){
                r--;
            }else{
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                while(l < r && nums[l -1] == nums[l]){
                    l++;
                }
            }
        }
     }   
     return ans;
    }
};
