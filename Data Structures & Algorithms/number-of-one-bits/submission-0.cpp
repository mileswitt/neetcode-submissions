class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            // read this as is n & 1 returns true then add 1 to the result otherwise add 0
            // n & 1 sees if the last bit of n is a 1 or a 0 we are doing last bit of n & 1 
            // so if its 1 it returns 1 if its 0 it returns 0
            res += (n & 1) ? 1 : 0;
            // n = n shifted right + 1
            // >> just shifts every remaining bit to the right 
            // 1011  →  shift right  →  0101
            n >>= 1;
        }
        return res;
    }
};
