class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;

        // saying that while what we are trying to add (n) doesnt already exist inside of our hash set
        // if n isnt found in the set already then the search returns a iterator called visit.end()
        while (visit.find(n) == visit.end()) {
            // insert new value into set
            visit.insert(n);
            // set our new n = to the sum of squares from old n with helper function
            n = sumOfSquares(n);
            if (n == 1) {
                return true;
            }
        }
        // if it != visit.end() then visit.find(n) worked meaning its in our set already so its a loop
        return false;
    }

    private:
        int sumOfSquares(int n) {
            int output = 0;

            // run while we still have digits to chop off and check in our number
            while (n > 0) {
                // chop off right most digit ex: 61 n % 10 = 1
                int digit = n % 10;
                // square the right most digit ex: 1 * 1 = 1
                digit = digit * digit;
                // add this digit to our output which will be the next n or number that we will 
                // check after the while loop finished running
                output += digit;
                // n = n with right digit chopped off cause we calculated it
                // ex: 61 -> 6
                n /= 10;
            }
            return output;
        }
};
