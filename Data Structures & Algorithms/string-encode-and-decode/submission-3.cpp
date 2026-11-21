class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto& str : strs){
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        
        string number = "";

        int i = 0;
        while(i < s.size()){
            if(s[i] == '#'){
                int num = stoi(number);

                string str = "";
                for(int j = 1; j <= num; j++){
                    str += s[i + j];
                }
                strs.push_back(str);
                number = "";
                i = i + num + 1;
                continue;
            }   
            number += s[i]; 
            i++;
        }
        return strs;
    }
};
