class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    
        
        std::vector<int> preff(arr.size() + 1);
        std::vector<int> ans;
        preff[0] = 0;
        for (std::size_t i = 0; i < arr.size(); i++) {
            preff[i + 1] = preff[i] ^ arr[i];
        }
        
        for (std::size_t i = 0; i < queries.size(); i++) {
            ans.push_back(preff[queries[i][1] + 1] ^ preff[queries[i][0]]);
        }
        
        return ans;
        
    }
};