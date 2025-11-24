class Solution {
    public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int currentRemainder = 0;

        for (int binaryDigit : nums) {

            currentRemainder = ((currentRemainder << 1) | binaryDigit) % 5;

            result.push_back(currentRemainder == 0);
        }

        return result;
    }
};