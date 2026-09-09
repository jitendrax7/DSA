class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long count = 0;
        int comma = 1;
        long long lower = 1000;
        while(lower<=n){
            long long upper = lower*1000-1;
            if(upper>n) upper = n;
            long long countNum = upper-lower+1;
            count += (countNum*comma);
            comma++;
            lower *= 1000;
        }

        return count;
    }
};