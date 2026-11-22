class Solution {
public:
    bool checkString(string s) {
        int f=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b' && f==-1) f=0;
            if(f==0 && s[i]=='a') return false;
        }
        return true;
    }
};