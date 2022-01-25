struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        std::unordered_set<std::pair<int, int>, pair_hash> pointsSet;
        int ans = std::numeric_limits<int>::max();
        for (std::size_t i = 0; i < points.size(); i++) {
            std::pair<int, int> currPoint = std::make_pair(points[i][0], points[i][1]);
            pointsSet.insert(currPoint);
        }
        
        for (std::size_t i = 0; i < points.size(); i++) {
            for (std::size_t j = i + 1; j < points.size(); j++) {
                std::pair<int, int> firstPoint = std::make_pair(points[i][0], points[i][1]);
                std::pair<int, int> secondPoint = std::make_pair(points[j][0], points[j][1]);
                
                if (firstPoint.first != secondPoint.first && firstPoint.second != secondPoint.second) {
                    std::pair<int, int> thirdPoint = std::make_pair(firstPoint.first, secondPoint.second);
                    std::pair<int, int> fourthPoint = std::make_pair(secondPoint.first, firstPoint.second);
                    if (pointsSet.find(thirdPoint) != pointsSet.end() && pointsSet.find(fourthPoint) != pointsSet.end()) {
                        ans = std::min(ans, (std::abs(firstPoint.second - thirdPoint.second) * std::abs(thirdPoint.first - secondPoint.first)));
                    }
                }
            }
        }
        if (ans == std::numeric_limits<int>::max()) {
            return 0;
        }
        return ans;
        
    }
};