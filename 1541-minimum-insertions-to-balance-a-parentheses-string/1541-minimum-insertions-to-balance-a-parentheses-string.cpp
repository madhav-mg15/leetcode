class Solution {
public:
    int minInsertions(string s) {
        int  n=s.length(), ans=0, cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else{
                if(i+1<n){
                    if(s[i]!=s[i+1]){
                        if(cnt==0) ans+=2;
                        else{
                            cnt--;
                            ans++;
                        }
                    }
                    else{
                        if(cnt==0) ans++;
                        else cnt--;
                        i++;
                    }
                }
                else{
                    if(cnt==0) ans+=2;
                    else{
                        cnt--;
                        ans++;
                    }
                }
            }
        } 
        return ans + 2*cnt;
    }
};