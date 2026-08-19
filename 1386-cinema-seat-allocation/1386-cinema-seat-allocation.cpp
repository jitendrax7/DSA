class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> m;
        for(auto & it:reservedSeats){
            int row = it[0];
            int s = it[1];
            m[row] = (m[row] |(1<<s));
        }

        auto isSetbit = [&](int bit, int i){
            return (bit&(1<<i))!=0;
        };
        int count = (n-m.size())*2;
        for(auto & it: m){
            bool group1 = (!isSetbit(it.second, 2) && !isSetbit(it.second, 3) && !isSetbit(it.second, 4)&&!isSetbit(it.second, 5));
            bool group2 = (!isSetbit(it.second, 4) && !isSetbit(it.second, 5) && !isSetbit(it.second, 6)&&!isSetbit(it.second, 7));
            bool group3 = (!isSetbit(it.second, 6) && !isSetbit(it.second, 7) && !isSetbit(it.second, 8)&&!isSetbit(it.second, 9));

            if(group1 && group3) count+=2;
            else if(group1) count++;
            else if(group3) count++;
            else if(group2) count++;
        }
        return count;
    }
};