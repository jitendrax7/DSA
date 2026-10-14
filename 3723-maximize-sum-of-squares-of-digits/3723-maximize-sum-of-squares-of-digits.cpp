class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9*num) return "";
        string ans = "";
        for(int i = 0;i<num;i++){
            if(sum>=9){
                ans += '9';
                sum -= 9;
            }else{
                ans += ('0'+sum);
                sum = 0; 
            }
        }
        return sum==0?ans:"";
    }
};