class Solution {
    public:
    int maxDistinctElements(vector<int>& nums, int k) {

        ranges::sort(nums);

        int distinctCount = 0;
        int previousValue = INT_MIN;

        for (int currentNum : nums) {

            int lowerBound = currentNum - k;

            int minValidValue = max(lowerBound, previousValue + 1);

            int upperBound = currentNum + k;

            int selectedValue = min(upperBound, minValidValue);

            if (selectedValue > previousValue) {

                distinctCount++;
                previousValue = selectedValue;
            }
        }

        return distinctCount;
    }
};