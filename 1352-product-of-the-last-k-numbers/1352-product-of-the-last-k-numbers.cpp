class ProductOfNumbers {
public:
    vector<int> nums;
    set<int> s;
    ProductOfNumbers() {
        nums = vector<int> ();
        s = set<int> ();
    }
    
    void add(int num) {
        if(num == 0) s.insert(nums.size());
        if(nums.empty() || nums.back() == 0){
            nums.push_back(num);
            return;
        }
        nums.push_back(nums.back()*num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        auto it = s.lower_bound(n-k);
        if(it!=s.end() && *it<n) return 0;
        if(k>=n || s.count(n-k-1)) return nums[n-1];
        return nums.back() / nums[n-k-1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */