class Solution {
    int countStores(vector<int> &quantities, int maxProductsPerStore) {
    int stores = 0;
    for (int i = 0; i < quantities.size(); i++) {
        stores += (quantities[i] + maxProductsPerStore - 1) / maxProductsPerStore;
    }
    return stores;
}
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
    if (n < quantities.size()) return -1;

    long long low = 1;  
    long long high = accumulate(quantities.begin(), quantities.end(), 0LL);  
    
    while (low < high) {
        long long mid = low + (high - low) / 2;
        
        
        if (countStores(quantities, mid) <= n) {
            high = mid;  
        } else {
            low = mid + 1;  
        }
    }
    return low;
    }

};

