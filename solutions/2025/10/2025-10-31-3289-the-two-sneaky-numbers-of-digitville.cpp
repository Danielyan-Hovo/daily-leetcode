class Solution {
    public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        vector<int> result;

        int frequency[100] = {0};

        for (int number : nums) {

            frequency[number]++;

            if (frequency[number] == 2) {
                result.push_back(number);
            }
        }

        return result;
    }
};