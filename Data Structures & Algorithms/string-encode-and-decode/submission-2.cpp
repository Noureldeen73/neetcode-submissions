class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded = "";
        for (auto str : strs)
        {
            encoded += "(";
            encoded += to_string(str.size());
            encoded += ")";
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        for (int i = 0; i < s.size(); i++)
        {
            string string_size = "";
            if (s[i] == '(')
            {
                i++;
            }
            while (s[i] != ')')
            {
                string_size += s[i];
                i++;
            }
            int size = stoi(string_size);
            string decoded = "";
            for (int j = i + 1; j - i <= size; j++)
            {
                decoded += s[j];
            }
            i += size;
            ans.push_back(decoded);
        }
        return ans;
    }
};