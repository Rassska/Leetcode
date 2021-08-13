class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    
    void addingpar(std::vector<std::string> &v, std::string str, int n, int m){
        if (n == 0 && m == 0) {
            v.push_back(str);
            return;
        }
        if (m > 0) {
            addingpar(v, str+")", n, m-1); 
        }
        if (n > 0) { 
            addingpar(v, str+"(", n-1, m+1); 
        }
    }
};