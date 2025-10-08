//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        int count = potions.size();

        for(int& spellStrength : spells){
            long long min = (success + spellStrength - 1) / spellStrength;
            int firstValidIndex = lower_bound(potions.begin(), potions.end(), min) - potions.begin();
            int successCount = count - firstValidIndex;
            result.push_back(successCount);
        }
        return result;
    }
};
