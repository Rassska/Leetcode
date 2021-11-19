class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        
        int amountOfPeople = k + 1;
        int left = *std::min_element(sweetness.begin(), sweetness.end());
        int right = std::accumulate(sweetness.begin(), sweetness.end(), 0);
        
        while (left < right) {
            int mid = (right + left + 1) / 2;
            int currSweetness = 0;
            int currPeopleWithChocolate = 0;
            
            for (auto s : sweetness) {
                currSweetness += s;
                
                if (currSweetness >= mid) {
                    currSweetness = 0;
                    currPeopleWithChocolate++;
                }
            }
            
            if (currPeopleWithChocolate >= amountOfPeople) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    
};