class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> keyValue;

        for (int i = 0; i<nums.size(); i++) {
            keyValue[nums[i]] = i;
        }

        for(int i = 0; i<nums.size(); i++) {
            int complement = target - nums[i];

            if(keyValue.count(complement) && keyValue[complement] != i) {
                return {i, keyValue[complement]};
            }
        }

        return {};

    }
};
