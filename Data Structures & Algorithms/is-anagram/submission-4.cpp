class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> s_map, t_map;

        for (char c : s){
            s_map[c]++; 
        }

        for (char c : t){
            t_map[c]++;
        }

        for (auto [k, v]: s_map){
            if (t_map[k] != v){
                return false;
            }
        }
        return true;
    }
};
