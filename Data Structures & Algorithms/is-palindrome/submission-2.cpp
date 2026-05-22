class Solution {
public:
    bool isPalindrome(string s) {

        int L = 0;
        int R = s.length() -1;

        while(L<R) {
            while(L < R && !alphaNum(s[L])) {
                L++;
            }
            while(R > L && !alphaNum(s[R])) {
                R--;
            }
            
            if (tolower(s[L]) != tolower(s[R]))
            {
                return false;
            }

            L++;
            R--;
        }

        return true;

    }

    bool alphaNum(char c) {
        return c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9';
    }
};
