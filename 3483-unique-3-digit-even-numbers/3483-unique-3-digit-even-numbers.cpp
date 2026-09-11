class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> v(10,0);
        for(auto x:digits) v[x]++;
        int ans=0;
        for(int i=100;i<1000;i+=2){
            int x = i;
            int a = x%10, b = (x/10)%10, c = x/100;
            v[a]--; v[b]--; v[c]--;
            if(v[a]>=0 && v[b]>=0 & v[c]>=0) ans++;
            v[a]++; v[b]++; v[c]++;
        }
        return ans;
    }
};