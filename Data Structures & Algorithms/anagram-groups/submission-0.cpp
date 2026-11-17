#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> mp;
        for (auto str : strs)
        {
            vector<int> characters(26);
            for (auto c : str)
            {
                characters[c - 'a']++;
            }
            mp[characters].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto element : mp)
        {
            ans.push_back(element.second);
        }
        return ans;
    }
};