class Solution {
public:
    int product(int n){
        int p =1;
        while(n>0){
            int r = n%10;
            p *= r;
            n /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while(product(n)%t){
            n++;
        }
        return n;
    }
};