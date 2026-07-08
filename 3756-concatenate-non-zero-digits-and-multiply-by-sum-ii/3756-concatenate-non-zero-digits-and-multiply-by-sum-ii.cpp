
// time complecity = O(n+q)
// space - O(4n)

class Solution {
public:
    const int MOD = 1e9+7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> nonZeroCount (n);
        vector<ll> prefixSum (n);
        vector<ll> numberUpTo (n);
        vector<ll> pow10 (n+1);

        prefixSum[0] = s[0]-'0';
        numberUpTo[0] = s[0]-'0';
        nonZeroCount[0] = s[0]-'0'=='0'?0:1;
        pow10[0] = 1;


        for(int i=1;i<n;i++){                    // O(n)
            if(s[i]=='0'){
                prefixSum[i] = prefixSum[i-1];
                numberUpTo[i] = numberUpTo[i-1];
                nonZeroCount[i] = nonZeroCount[i-1];
            }else{
                prefixSum[i] = (prefixSum[i-1]+s[i]-'0' ) % MOD;
                numberUpTo[i] = (numberUpTo[i-1]*10 + s[i]-'0') % MOD;
                nonZeroCount[i] = nonZeroCount[i-1]+1;
            }
            pow10[i] = (pow10[i-1]*10) % MOD;
        }

        pow10[n] = pow10[n-1]*10;


        int q = queries.size();
        vector<int> ans (q);

        for(int i=0;i<q;i++){               // O(q)
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = prefixSum[r] - ( l==0?0:prefixSum[l-1] );
            int k = nonZeroCount[r] - ( l==0?0:nonZeroCount[l-1] );
            int numbefore =  l==0?0:numberUpTo[l-1] ;
            ll x = ( numberUpTo[r] - (numbefore*pow10[k] % MOD) + MOD ) % MOD;

            ans[i] = (x*sum) %MOD;
            
        }

        return ans ;
    } 
};