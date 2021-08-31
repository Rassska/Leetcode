class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            
        std::vector<std::vector<int>> m_graph(numCourses, std::vector<int>());
        std::vector<int> m_inDegree(numCourses, 0);
        std::vector<int> res;
        
        for (auto pair : prerequisites) {
            m_graph[pair[1]].push_back(pair[0]);
            m_inDegree[pair[0]]++;
        }
        
        std::queue<int> que;
        
        for (std::size_t i = 0; i < m_inDegree.size(); i++) {
            if (m_inDegree[i] == 0) {
                que.push(i);
            }
        }
        
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            res.push_back(u);
            
            for (auto v : m_graph[u]) {
                m_inDegree[v]--;
                
                if (m_inDegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        
        return res.size() == numCourses ? res : std::vector<int>();
        
        
        
        
        
        
        
        
        
    }
    
private:
    
};