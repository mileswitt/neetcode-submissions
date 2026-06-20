class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // key, value
        // you look up the index (value) by giving it a char (key)
        // when you do mp.find(a) you will get back the key/index it is stored at
        unordered_map<char, int> mp;
        int l = 0;
        int res = 0;

        // iterate through size of string with r pointer for each iteration
        for (int r = 0; r < s.size(); r++) {
            // if the char at the current index r is in the map already
            if (mp.find(s[r]) != mp.end()) {
                // l is going to be = to the index of the duplicate value that is stored in the map + 1
                // we want to move the window (l) past that index and not include it
                // we check the max because we dont want the window to move backwards
                // consider the string abcba this is an example of max in use.
                l = max(mp[s[r]] + 1, l);
            }
            // if the value isnt in the map add it to the map. 
            mp[s[r]] = r;
            // set res to be either the longest window max and check if the current window is the biggest
            res = max(res, r - l + 1);
        }
        return res;        
    }
};
