class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> rightSideMatchChar(n,0);
        int i =n-1;
        int j =m-1;
        int match = 0;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                match ++;
                j--;
            }
            rightSideMatchChar[i] = match;
            i--;
        }
        i = 0;
        j = 0;
        vector<int> seq;
        bool isPower = true;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }else if(isPower && i+1<n && rightSideMatchChar[i+1]>=m-j-1){
                seq.push_back(i);
                isPower = false;
                j++;
            }
            i++;
        }

        if(j==m) return seq;
        return {};
    }
};