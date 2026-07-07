class Solution {
public:
    long long sumAndMultiply(int n) {
        
        int digitSum =0;
        int nonZeroDigit =0;

        int placevalue = 1;
        while(n>0){
            int digit = n%10;
            if(digit!=0){
                nonZeroDigit = (digit*placevalue)+nonZeroDigit;
                placevalue *= 10;
            }
            digitSum += digit;
            n /= 10;
        }
        return 1LL*digitSum*nonZeroDigit;
    }
};