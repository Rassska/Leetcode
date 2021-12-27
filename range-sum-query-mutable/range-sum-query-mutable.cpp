class SegTree {
public:
    int leftMost, rightMost;
    SegTree* lChild = nullptr;
    SegTree* rChild = nullptr;
    int sum;
    
    SegTree (int leftMost, int rightMost, std::vector<int>& nums) {
        this->leftMost = leftMost;
        this->rightMost = rightMost;
        
        if (leftMost == rightMost) {
            sum = nums[leftMost];
        } else {
            int mid = (leftMost + rightMost) / 2;
            lChild = new SegTree(leftMost, mid, nums);
            rChild = new SegTree(mid + 1, rightMost, nums);
            recacl();
        }
    }
    
    void recacl() {
        if (leftMost == rightMost) {
            return;
        }
        sum = lChild->sum + rChild->sum;
    }
    
    void pointUpdate(int index, int newValue) {
        if (leftMost == rightMost) {
            sum = newValue;
            return ;
        }
                
        if (index <= lChild->rightMost) {
            lChild->pointUpdate(index, newValue);
        } else {
            rChild->pointUpdate(index, newValue);
        }
        recacl();
        
    }
    
    int rangeSum(int left, int right) {
        // entirely disjoint
        if (left > rightMost || right < leftMost) { 
            return 0;
        }
        // covers us
        
        if (left <= leftMost && right >= rightMost) {
             return sum;
        }
        
        // we don't know
        
        return lChild->rangeSum(left, right) + rChild->rangeSum(left, right);
        
    }
    
};



class NumArray {
public:
    NumArray(vector<int>& nums) {
        st = new SegTree(0, nums.size() - 1, nums);
    }
    
    void update(int index, int val) {
        st->pointUpdate(index, val);
    }
    
    int sumRange(int left, int right) {
        return st->rangeSum(left, right);
    }
    
private:
    SegTree* st;
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */