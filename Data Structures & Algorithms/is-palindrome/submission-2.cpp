class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int lPointer = 0, rPointer = n - 1;
        while (lPointer < rPointer) {
            while ((!isalpha(s[lPointer]) && !isdigit(s[lPointer])) && lPointer < rPointer) {
                lPointer++;
            }
            while ((!isalpha(s[rPointer]) && !isdigit(s[rPointer])) && lPointer < rPointer) {
                rPointer--;
            }
            if (tolower(s[lPointer]) != tolower(s[rPointer])) {
                return false;
            }
            lPointer++;
            rPointer--;
        }
        return true;
    }
};
