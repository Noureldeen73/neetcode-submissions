class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> need = {{')', '('}, {']', '['}, {'}', '{'}};

        stack<char> st;

        for(auto& c : s){
            if(!need.count(c)){
                st.push(c);
            }else{
                if(st.empty()|| st.top() != need[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
