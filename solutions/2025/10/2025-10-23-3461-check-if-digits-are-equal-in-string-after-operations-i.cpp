class Solution {
    public:
    bool hasSameDigits(string s) {
        int stringLength = s.size();
        string workingString = s;

        for (int currentLength = stringLength - 1; currentLength > 1; --currentLength) {

            for (int position = 0; position < currentLength; ++position) {

                int currentDigit = workingString[position] - '0';
                int nextDigit = workingString[position + 1] - '0';
                int sumModTen = (currentDigit + nextDigit) % 10;
                workingString[position] = sumModTen + '0';
            }
        }

        return workingString[0] == workingString[1];
    }
};