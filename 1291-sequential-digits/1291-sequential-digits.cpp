// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> ans;
//         for(int i=1;i<=9;i++){
//             int num = i;
//             for(int j =i+1;j<=9;j++){
//                 num = num*10+j;
//                 if(num>= low && num<= high){
//                     ans.push_back(num);
//                 }
//             }
//         }

//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        queue<int> q;
        for(int i =1;i<9;i++){
            q.push(i);
        }
        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num>= low && num<= high){
                ans.push_back(num);
            }
            int lstdigit = num%10;
            if(num<=high && lstdigit<9 ){
                q.push(num*10+lstdigit+1);
            }
        }

        return ans;
    }
};