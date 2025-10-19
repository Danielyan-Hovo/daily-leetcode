class Solution {
    public:
    string findLexSmallestString(string s, int a, int b) {

        queue<string> bfsQueue{{s}};
        unordered_set<string> visited{{s}};
        string minString = s;
        int stringLength = s.size();

        while (!bfsQueue.empty()) {
            string currentString = bfsQueue.front();
            bfsQueue.pop();

            minString = min(minString, currentString);

            string addResult = currentString;
            for (int i = 1; i < stringLength; i += 2) {

                addResult[i] = (addResult[i] - '0' + a) % 10 + '0';
            }

            string rotateResult = currentString.substr(stringLength - b) +
            currentString.substr(0, stringLength - b);

            for (const auto& transformedString : {addResult, rotateResult}) {

                if (!visited.count(transformedString)) {
                    visited.insert(transformedString);
                    bfsQueue.emplace(transformedString);
                }
            }
        }

        return minString;
    }
};