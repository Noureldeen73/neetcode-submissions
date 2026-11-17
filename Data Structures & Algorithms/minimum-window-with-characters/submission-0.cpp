class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count, window;
        for(auto c : t){
            count[c]++;
        }
        int have = 0, need = count.size();
        int start = -1;
        int size = INT_MAX;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;
            if(count.count(c) && window[c] ==  count[c]){
                have++;
            }
            while(have == need){
                if(r - l + 1 < size){
                    size = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if(count.count(s[l]) && window[s[l]] < count[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return size == INT_MAX ? "" : s.substr(start, size);
    }
};
