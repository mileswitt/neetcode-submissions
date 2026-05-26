class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count; // key value pairs count : number
        // we have index as first list then a list of numbers that appear that index amount of times as frequency
        vector<vector<int>> freq(nums.size() + 1); // list of list for storing the list of numbers that exist at a given index
        
        // increment the count of the frequency of which we have seen the value in nums
        for (int n : nums) {
            count[n] = 1 + count[n];
        }

        // const for mutability so we dont change any vlaues by accident
        // auto allows us to automatically do type inference instead of manually doint it
        // range based for loop of for each instance of a entry in count
        // we swap the pair so we had it in the map as (value, count) 
        // now we take the count from the second part and put that in the first list
        //this makes it so the index is the count that we wnat to store the value at
        // then we store the value at that count and create a list of any values we are storing at that count with our second vector
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        //create result vector we will return
        vector<int> res;

        //start at the end of the freq list 
        // we start at the highest index becuase that will be storing the most frequently occuring value
        // remember the index is the count of times it appeared so we start highest go lower
        // for each value stored at the farthest index put that in our result vector
        // so we are storing the actual value from the furthest away count or the list of those values inside of our result vector
        // if the result vector size is the same as k then we just return becasue thats the most frequent ones
        for (int i = freq.size()-1; i>0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;

    }
};
