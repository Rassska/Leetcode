class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        std::stack<int> st;
        std::vector<int> ans;
        for (std::size_t i = 0; i < asteroids.size(); i++) {
            
            if (st.empty() || asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                
            } 
        }
        
        ans.resize(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
        
    }
};