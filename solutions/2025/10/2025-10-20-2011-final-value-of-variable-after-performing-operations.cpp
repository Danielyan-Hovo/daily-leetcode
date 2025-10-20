class Solution {
    public:
    int finalValueAfterOperations(vector<string>& operations) {

        int result = 0;

        for (const auto& operation : operations) {

            result += (operation[1] == '+') ? 1 : -1;
        }

        return result;
    }
};