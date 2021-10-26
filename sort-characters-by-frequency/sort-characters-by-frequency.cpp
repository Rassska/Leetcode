class Solution {
public:
    string frequencySort(string s) {
        
        std::unordered_map<char, int> hashMap;
        std::vector<std::pair<int, char>> frequency;
        
        std::string ans = "";
        
        for (auto currChar : s) {
            hashMap[currChar]++;
        }
        
        for (auto it : hashMap) {
            frequency.push_back({it.second, it.first});
        }
        
        std::sort(frequency.rbegin(), frequency.rend());
        
        for (auto pair : frequency) {
            while (pair.first--) {
                ans += pair.second;
            }
        }
        return ans;
        
        
        
        
        
    }
};