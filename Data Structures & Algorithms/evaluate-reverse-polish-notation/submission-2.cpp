class Solution {
public:
    enum class Operation { Plus, Minus, Mul, Div, Unknown };
    int evalRPN(vector<string>& tokens) {
        set<string> operations = {"+", "-", "*", "/"};
        stack<int> st;
        int n = tokens.size();

        for(auto& token: tokens){
            if(token.size() == 1 && operations.count(token)){
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                switch(resolveOperation(token)){
                    case Operation::Plus: st.push(first + second);break;
                    case Operation::Minus: st.push(first - second);break;
                    case Operation::Mul: st.push(first * second);break;
                    case Operation::Div: st.push(first / second);
                }
            }else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }

    Operation resolveOperation(const string& operation){
        unordered_map<string, Operation> operationMap={
            {"+", Operation::Plus},
            {"-", Operation::Minus},
            {"*", Operation::Mul},
            {"/", Operation::Div}
        };

        auto it = operationMap.find(operation);
        return (it != operationMap.end()) ? it->second : Operation::Unknown;
    }
};
