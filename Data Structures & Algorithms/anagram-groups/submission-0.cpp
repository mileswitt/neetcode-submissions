class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // hash map we store the strings of charachters along with a list of the words that are anagrams for that string
        unordered_map<string, vector<string>> res;

        // for each word in the input list
        for (const auto& s : strs) {
            // create a list of 26 0s
            vector<int> count(26, 0);
            // for each character in the string we are on
            for (char c : s) {
                // increment the count of the letter mapped to that index by one so a = 0 b = 1 so on
                // this is done by saying take the current char ascii value and subtract it by a so by 1 essentially
                // that makes it so its the index vale 
                count[c - 'a']++;
            }

            // we want to insert the first value manually into the list
            // if we dont we will have a trailing or leading comma at the end
            string key = to_string(count[0]);
            // start at 1 because we already inserted at 0
            // go 1-25 
            for (int i = 1; i < 26; i++) {
                // comma goes first because we started with a value at 0
                // we add comma to seperate it in cases of like 11
                // this creates our key tho so 1, 0, 0, 1, 1 
                key += ',' + to_string(count[i]);
            }
            // go to the slot on the hashmap that has the key for the words we are pushing
            // if it doesnt exist c++ creates that key or inserts it into the map
            // push the word onto the list at that key
            res[key].push_back(s);
        }
        // list of list or list of words that are anagrams
        vector<vector<string>> result;
        // loop over every entry in our hash map
        for (const auto& pair : res) {
            // push onto our result vector we will return
            // push the list of words that are anagrams onto the output vector
            result.push_back(pair.second);
        }
        return result;
        
    }
};
