class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int len = 101;
        string beautifulString = "";
        int count = 0;
        for(int right =0;right<s.size();right++){
            if(s[right]=='1') count++;
            while( left<=right && count==k){
                int length = right-left+1;
                string subs = s.substr(left,length);
                if(length<len || (length==len && subs<beautifulString) ){
                    len = length;
                    beautifulString = subs;
                }
                if(s[left]=='1') count--;
                left++;
            }
        }
        return beautifulString;
    }
};