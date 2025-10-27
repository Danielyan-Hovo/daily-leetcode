class Solution {
    public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int previousDeviceCount = 0;

        for (const auto& row : bank) {

            int currentDeviceCount = count(row.begin(), row.end(), '1');

            if (currentDeviceCount > 0) {

                totalBeams += previousDeviceCount * currentDeviceCount;

                previousDeviceCount = currentDeviceCount;
            }
        }

        return totalBeams;
    }
};