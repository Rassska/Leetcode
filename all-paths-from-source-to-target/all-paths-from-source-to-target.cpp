class Solution {
public:
    
    void dfs (int node, int lastNode, std::vector<std::vector<int>>& graph) {
        
        path.push_back(node);
        
        if (node == lastNode) {
            result.push_back(path);
        }
        
        for (std::size_t i = 0; i < graph[node].size(); i++) {
            dfs(graph[node][i], lastNode, graph);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        dfs(0, graph.size() - 1, graph);
        return result;
    }
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
};