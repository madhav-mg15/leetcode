class Solution {
public:
    int minOperations(string s) {
        int frq[26] = {0};
        int n = s.length(), f=0;
        for(int i=0;i<n;i++){
            frq[s[i]-'a']++;
            if(i>0 && s[i]<s[i-1]) f=1; 
        }
        if(n==1 || f==0) return 0;
        if(n==2) return s[0]<=s[1] ? 0 : -1;
        char ch1=' ', ch2=' ';
        for(int i=0;i<26;i++){
            if(frq[i]){
                if(ch1==' ') ch1 = i+'a';
                ch2 = i+'a';
            }
        }
        if(s[0]==ch1 || s[n-1]==ch2) return 1;
        if(s[0]==ch2 && frq[ch1-'a']==1 && s[n-1]==ch1 && frq[ch2-'a']==1) return 3;
        return 2;
    }
};