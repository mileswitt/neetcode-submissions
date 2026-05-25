class Solution {
public:
    int trap(vector<int>& height) {

        if (height.empty()) {
            return 0;
        }

        int l = 0;
        int r = height.size()-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int result = 0;

        while (l<r) {
            if (height[l] < height[r]) {
                l++;
                leftMax = max(height[l], leftMax);
                result += leftMax - height[l];
            } else {
                r--;
                rightMax = max(height[r], rightMax);
                result += rightMax - height[r];
            }
        }
        return result;
    }
};
