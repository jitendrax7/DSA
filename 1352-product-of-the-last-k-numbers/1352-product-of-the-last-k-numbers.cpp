class ProductOfNumbers {
public:
    vector<int> pro;

    ProductOfNumbers() { pro.push_back(1); }

    void add(int num) {
        if (num == 0) {
            pro.clear();
            pro.push_back(1);
        } else {
            pro.push_back(pro.back() * num);
        }
    }

    int getProduct(int k) {
        int n = pro.size();
        if (k >= n)
            return 0;
        return pro.back() / pro[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */