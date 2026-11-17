class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_set<char> mp;
        int l = 0, ans = 0, r = 0;
        while (l < n)
        {
            while (r < n && !mp.count(s[r]))
            {
                mp.insert(s[r]);
                r++;
            }
            ans = max(ans, r - l);
            while (l < n && s[l] != s[r])
            {
                mp.erase(s[l]);
                l++;
            }
            mp.erase(s[l]);
            l++;
        }
        ans = max(ans, r - l);
        return ans;
    }
};
