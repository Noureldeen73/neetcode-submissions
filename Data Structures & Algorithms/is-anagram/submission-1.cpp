class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqs;
        unordered_map<char, int> freqt;
        int n = s.size(), m = t.size();
        if(n != m)
        {
            return false;
        }
        for(int i = 0; i < n; i++)
        {
            freqs[s[i]]++;
            freqt[t[i]]++;
        }
        for(auto p : freqs)
        {
            if(p.second != freqt[p.first])
            {
                return false;
            }
        }
        return true;
        
    }
};
