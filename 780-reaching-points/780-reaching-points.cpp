class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        bool ans = false;
    /*
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(sx, sy));
        
        while (!q.empty()) {
            std::pair<int, int> currPair = q.front(); q.pop();
            if (currPair.first == tx && currPair.second == ty) {
                ans = true;
                break;
            }
            if (currPair.first + currPair.second > tx && currPair.first + currPair.second > ty) {
                continue;
            }
            q.push(std::make_pair(currPair.first + currPair.second, currPair.second));
            q.push(std::make_pair(currPair.first, currPair.second + currPair.first));
        }
        return ans;
    */
        
        // (x, y) -> (x, x + y) -> (x, 2x + y) -> (3x + y, 2x + y)
        
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty > sy) tx %= ty;
                else return (tx - sx) % ty == 0; 
            } else {
                if (tx > sx) ty %= tx;
                else return (ty - sy) % tx == 0;
            }
        }
        
        return (tx == sx && ty == sy);
    }
};


/*

    operation:
    (x, y) -> (x, x + y) / (x + y, y);
    
    sx = 1, sy = 1, tx = 3, ty = 5
    [1, 1] -> [3, 5]
    
    [1, 1] -> [1, 2]
    [1, 2] -> [3, 2]
    [3, 2] -> [3, 5]
    
    

    [1, 1] -> [1, 2] / [2, 1]
    
        - [1, 2] -> [3, 2] / [1, 3]
        - [2, 1] -> [3, 1] / [2, 3]
        
        
        
        (x, y) -> (x, x + y) -> (k * y + x, t * x + y)
*/