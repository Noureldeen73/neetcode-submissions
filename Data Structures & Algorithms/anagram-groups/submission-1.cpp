class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (auto &s: strs){
            int count[26] = {0};

            for(auto c: s){
                count[c - 'a']++;
            }

            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(count[i]);
                key += '#';
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& [k, v]: groups){
            res.push_back(v);
        }
        return res;
    
    }
};
