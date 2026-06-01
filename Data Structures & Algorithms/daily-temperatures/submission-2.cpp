class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // res(size, set value for each index)
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            // while the stack isnt empty and temp is greater then the temp value stored at the top of the stack
            while (!st.empty() && t > st.top().first) {
                // auto is just type inference
                // create a variable to hold the pair at the top of the stack
                auto pair = st.top();
                st.pop();
                // i is current day, topPair.second is the day that was waiting
                // the difference is how many days it had to wait
                res[pair.second] = i - pair.second;
            }
            // push current day onto stack — it's now waiting for its own warmer day
            st.push({t, i});
        }
        return res;
    }
};
