class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> A;

        for (int i = 0; i<nums.size(); i++) {
            A[nums[i]] = i;
        }

        for (int i = 0; i<nums.size(); i++) {
            int diff = target-nums[i];

            if (A.count(diff) && A[diff] != i) {
                return {i,A[diff]};
            }
        }

        return {};

    }
};
