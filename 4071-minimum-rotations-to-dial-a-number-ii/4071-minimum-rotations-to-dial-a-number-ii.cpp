class Solution {
public:
    int minRotations(int n, string s) {
        vector<int> v(n,0);
        int ans=0, total=0;
        char pr = '0';
        for(int i=0;i<n;i++){
            char ch = s[i];
            v[i] = min(abs((ch-'0')-(pr-'0')), 10-abs((ch-'0')-(pr-'0')));
            pr = ch;
            total += v[i];
        }
        ans = total;
        for(int i=0;i<n-1;i++){
            if(i==0){
                int mn = min(abs((s[n-1]-'0')), 10-abs((s[n-1]-'0')));
                ans = min(ans, total-v[i]+mn);
            }
            else{
                int mn = min(abs((s[n-1]-'0')-(s[i-1]-'0')), 10-abs((s[n-1]-'0')-(s[i-1]-'0')));
                ans = min(ans, total-v[i]+mn);
            }
        }
        return ans;
    }
};