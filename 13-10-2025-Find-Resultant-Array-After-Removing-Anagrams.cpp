//https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        auto notAnagrams = [](const string& str1, const string& str2) -> bool {
            if(str1.size() != str2.size()) {
                return true;
            }
            int frequency[26] = {0};
            for(const char& ch : str1) {
                frequency[ch - 'a']++;
            }

            for(const char& ch : str2) {
                frequency[ch - 'a']--;
                if(frequency[ch - 'a'] < 0){
                    return true;
                }
            }

            return false;
        };

        vector<string> res;
        res.push_back(words[0]);
        for(int i = 1; i < words.size(); i++) {
            if(notAnagrams(words[i - 1], words[i])){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
