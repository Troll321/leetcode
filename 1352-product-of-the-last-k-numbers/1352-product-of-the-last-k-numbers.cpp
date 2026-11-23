typedef long long ll;
const ll MAXN = 4e4 + 5;
ll idx = 0, lst0 = 0, pref[MAXN];
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        pref[0] = 1;
        idx = 0;
        lst0 = -1;
    }
    
    void add(int num) {
        idx++;
        if(num == 0) {
            lst0 = idx;
            pref[idx] = 1;
        } else {
            pref[idx] = pref[idx-1]*(ll)num;
        }
    }
    
    int getProduct(int k) {
        if(idx-k+1 <= lst0) {return 0;}
        return pref[idx]/pref[idx-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */