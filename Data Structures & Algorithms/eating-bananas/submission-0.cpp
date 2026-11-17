class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n  = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            long long total = 0;
            for(auto p : piles){
                total += ceil(static_cast<double>(p) /  mid);
            }
            if(total <= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
