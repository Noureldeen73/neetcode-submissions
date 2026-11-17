class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        int open = 0;
        if(s.size() & 1) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')'){
                if(brackets.empty() || brackets.top() != '('){
                    return false;
                }
                brackets.pop();
            }
            else if (s[i] == ']'){
                if(brackets.empty() || brackets.top() != '['){
                    return false;
                }
                brackets.pop();
            }
            else if (s[i] == '}'){
                if(brackets.empty() || brackets.top() != '{'){
                    return false;
                }
                brackets.pop();
            }
            else {
                brackets.push(s[i]);
                open++;
                continue;
            }
            open--;
        }
        return open == 0;
    }
};
