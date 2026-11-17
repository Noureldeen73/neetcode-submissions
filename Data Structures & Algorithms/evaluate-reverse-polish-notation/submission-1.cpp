
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].size() == 1 && tokens[i][0] == '+')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 + n1);
            }
            else if (tokens[i].size() == 1 && tokens[i][0] == '-')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 - n1);
            }
            else if (tokens[i].size() == 1 && tokens[i][0] == '*')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 * n1);
            }
            else if (tokens[i].size() == 1 && tokens[i][0] == '/')
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 / n1);
            }
            else
            {
                int num = 0;
                for (int j = 0; j < tokens[i].size(); j++)
                {
                    if (tokens[i][j] == '-')
                        continue;
                    num *= 10;
                    num += tokens[i][j] - '0';
                }
                if (tokens[i][0] == '-')
                {
                    num *= -1;
                }
                st.push(num);
            }
        }
        return st.top();
    }
};
