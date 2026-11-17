class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = INT_MAX;
        int pivot = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]){
                if(nums[mid] < ans){
                    pivot = mid;
                    ans = nums[mid];
                }
                l = mid + 1;
            }
            else{
                if(nums[mid] < ans){
                    pivot = mid;
                    ans = nums[mid];
                }
                r = mid - 1;
            }
        }
        cout << pivot;
        if(nums[pivot] <= target && target <= nums[n - 1]){
            return binarySearc(pivot, n - 1, target, nums);
        }
        else{
            return binarySearc(0, pivot - 1, target, nums);
        }
    }
    int binarySearc(int l, int r, int target, vector<int> &nums){
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                r  = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
