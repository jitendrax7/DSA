class Solution {
public:
    int maxDistance(string moves) {
        
        int x =0;
        int y =0;
        int w =0;

        for(auto c:moves){
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='L') x--;
            else if(c=='R') x++;
            else w++;
        }

        return abs(x)+abs(y)+w;
    }
};