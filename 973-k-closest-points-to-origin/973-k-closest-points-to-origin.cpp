typedef pair<double, std::vector<std::vector<int>>> pr;
class Solution {
public:
    
    double getDist(int x, int y) {
        return sqrt((std::pow(x, 2) + std::pow(y, 2)));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        
        for (std::size_t i = 0; i < points.size(); i++) {
            double dist = getDist(points[i][0], points[i][1]);
            std::vector<std::vector<int>> temp;
            temp.push_back({points[i][0], points[i][1]});
            minHeap.push({dist, temp});
        }
        
        while (k--) {
            std::vector<int> temp;
            temp.push_back(minHeap.top().second[0][0]);
            temp.push_back(minHeap.top().second[0][1]);
            closestPoints.push_back(temp);
            minHeap.pop();
        }
        return closestPoints;
    }
    
private:
    std::priority_queue<pr, std::vector<pr>, std::greater<pr>> minHeap;
    std::vector<std::vector<int>> closestPoints;
};
