// # apporoch 1

// you can also remove map and use a constant varible a,b,c for leetcode submistion in 0 ms

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n =s.size();
//         unordered_map<char,int> m= {{'a',-1},{'b',-1},{'c',-1}};
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             m[s[i]] = i;
//             if(m['a']>=0 && m['b']>=0 && m['c'] >= 0){
//                 int mini = min({m['a'], m['b'], m['c']});
//                 ans += mini+1;
//             }
            
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();
        int a= -1, b= -1,c = -1;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') a = i;
            else if(s[i]=='b')b =i ;
            else c =i;
            if(a>=0 && b>=0 && c >= 0){
                int mini = min({a, b, c});
                ans += mini+1;
            }
        }
        return ans;
    }
};


// # approch 2

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n =s.size();
//         unordered_map<char,int> m= {{'a',0},{'b',0},{'c',0}};
//         int l = 0;
//         int ans = 0;
//         for(int r=0;r<n;r++){
//             m[s[r]]++;
//             while(m['a']>0 && m['b']>0 && m['c']>0){
//                 m[s[l]]--;
//                 l++;
//             }
//             ans += l;
//         }

//         return ans;
//     }
// };

// optimize use of constent variable

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n =s.size();

//         int a= 0, b= 0,c = 0;
//         int l = 0;
//         int ans = 0;
//         for(int r=0;r<n;r++){
//             if(s[r]=='a') a++;
//             else if(s[r]=='b') b++;
//             else c++;
//             while(a>0 && b>0 && c>0){
//                 if(s[l]=='a') a--;
//                 else if(s[l]=='b') b--;
//                 else c--;
//                 l++;
//             }
//             ans += l;
//         }
//         return ans;
//     }
// };

