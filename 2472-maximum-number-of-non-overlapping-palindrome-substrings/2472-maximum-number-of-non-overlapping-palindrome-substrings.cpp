string s;
int n,k;
vector<int> dp;
class Solution {
public:
    int f(int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0,fl=0;
        for(int j=i;j<n;j++){
            int l=j, r=j;
            while(l>=i && r<n && s[l]==s[r]){
                int len=r-l+1;
                if(len==k){
                    ans=max(ans,1+f(r+1));
                    fl=k-1;
                    break;
                }
                if(len==k+1){
                    ans=max(ans,1+f(r+1));
                    fl=k;
                    break;
                }
                if(len>k+1){
                    fl=0;
                    break;
                }
                l--;
                r++;
            }
            if(fl) continue;
            l=j, r=j+1,fl=0;
            while(l>=i && r<n && s[l]==s[r]){
                int len=r-l+1;
                if(len==k){
                    ans=max(ans,1+f(r+1));
                    fl=k-1;
                    break;
                }
                if(len==k+1){
                    ans=max(ans,1+f(r+1));
                    fl=k;
                    break;
                }
                if(len>k+1){
                    fl=0;
                    break;
                }
                l--;
                r++;
            }
            j+=fl;
        }
        if(ans==0) ans=max(ans,f(i+1));
        return dp[i]=ans;
    }
    int maxPalindromes(string s1, int k1) {
        s=s1, k=k1;
        n=s.length();
        dp = vector<int> (n+1,-1);
        return f(0);
    }
};