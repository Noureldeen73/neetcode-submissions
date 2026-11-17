class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int numOfBrackets = 2 * n;
        vector<string> ans;
        string curr = "";
        generateCombinations(ans, curr, '(', 1, numOfBrackets);
        return ans;
    }
    void  generateCombinations(vector<string> &ans, string &curr, char toAdd, int numOfOpen,int total){
        curr.push_back(toAdd);
        if(curr.size() == total){
            if(numOfOpen == 0){
            ans.push_back(curr);
            }
            return;
        }
        if(numOfOpen == 0){
            generateCombinations(ans, curr, '(', numOfOpen + 1, total);
            curr.pop_back();
        }
        else{
            generateCombinations(ans, curr, '(', numOfOpen + 1, total);
            curr.pop_back();
            generateCombinations(ans, curr, ')', numOfOpen - 1, total);
            curr.pop_back();
        }
    }
};