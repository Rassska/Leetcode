class SegTree {
public:
    int leftMost, rightMost;
    SegTree* lChild = nullptr;
    SegTree* rChild = nullptr;
    int max;
    
    SegTree(int leftMost, int rightMost, std::vector<int>& nums) {
        this->leftMost = leftMost;
        this->rightMost = rightMost;
        
        if (leftMost == rightMost) {
            max = nums[leftMost];
        } else {
            int mid = leftMost + (rightMost - leftMost) / 2;
            
            lChild = new SegTree(leftMost, mid, nums);
            rChild = new SegTree(mid + 1, rightMost, nums);
            recalc();
        }
    }
    
    void recalc() {
        if (leftMost == rightMost) {
            return;
        }
        max = std::max(lChild->max, rChild->max);
    }
    
    void pointUpdate(int index, int newValue) {
        if (leftMost == rightMost) {
            max = newValue;
            return;
        }
        
        if (index <= lChild->rightMost) {
            lChild->pointUpdate(index, newValue);
        } else {
            rChild->pointUpdate(index, newValue);
        }
        recalc();
    }
    int rangeMax(int left, int right) {
        if (left > rightMost || right < leftMost) {
            return INT_MIN;
        }
        
        if (left <= leftMost && right >= rightMost) {
            return max;
        }
        
        return std::max(lChild->rangeMax(left, right), rChild->rangeMax(left, right));
    }
};





class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        st = new SegTree(0, nums.size() - 1, nums);
        
        int left = 0;
        std::vector<int> maxSlidingWindow;
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            
            if (i - left + 1 == k) {
                maxSlidingWindow.push_back(st->rangeMax(left, i));
                left++;
            }
            
        }
        return maxSlidingWindow;
        
        
    }
private:
    SegTree* st;
};