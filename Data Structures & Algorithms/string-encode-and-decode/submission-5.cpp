class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for(auto& str : strs){
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        string number = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                number += s[i];
            }else{
                int num = stoi(number);

                strs.push_back(s.substr(i + 1, num));

                i += num;
                number = "";
            }
        }

        return strs;
    }
};
