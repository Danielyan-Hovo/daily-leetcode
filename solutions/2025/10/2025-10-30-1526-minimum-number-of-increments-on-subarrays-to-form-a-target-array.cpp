class Solution {
    public:
    int minNumberOperations(vector<int>& target) {

        int totalOperations = target[0];

        for (int i = 1; i < target.size(); ++i) {

            if (target[i] > target[i - 1]) {
                totalOperations += target[i] - target[i - 1];
            }

        }

        return totalOperations;
    }
};