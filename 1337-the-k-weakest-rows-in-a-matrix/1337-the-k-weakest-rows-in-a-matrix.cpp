

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      
        for(int i = 0; i < mat.size(); i++){
            int sum=0;
            for(int j = 0; j < mat[i].size(); j++){
                sum += mat[i][j];
            }
            minHeap.push({sum, i});
        }
        
        while (k--){
            indecies.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return indecies;
    }
    
private:
    std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, greater<std::pair<int, int>>> minHeap;
    std::vector<int> indecies;
};