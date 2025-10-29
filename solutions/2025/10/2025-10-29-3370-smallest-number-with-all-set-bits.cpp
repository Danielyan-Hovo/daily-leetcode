class Solution {
    public:
    int smallestNumber(int n) {

        int powerOfTwo = 1;

        while (powerOfTwo - 1 < n) {
            powerOfTwo <<= 1;
        }

        return powerOfTwo - 1;
    }
};