class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++)
        {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.first > b.first; });
        stack<double> st;
        for (auto &p : pairs)
        {
            double time = (double)(target - p.first) / p.second;
            if (st.empty())
            {
                st.push(time);
                continue;
            }
            if (time > st.top())
            {
                st.push(time);
            }
        }
        return st.size();
    }
};
