class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> res;
        int l = 0;
        int count = 1;
        int r = l + 1;

        while (l < temperatures.size()) {
            if (r == temperatures.size()) {
                res.push_back(0);
                l++;
                r = l + 1;
                count = 1;
            } 
            else if (temperatures[l] >= temperatures[r]) {
                count++;
                r++;
            } 
            else if (temperatures[l] < temperatures[r]) {
                res.push_back(count);
                l++;
                r = l + 1;
                count = 1;
            }
        }
        return res;
    }
};
