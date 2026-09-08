using ll = long long;
class Solution {
public:
    int len(ll x){
        int n=0;
        while(x){
            x/=10;
            n++;
        }
        return n;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        queue<ll> q;
        set<int> s;
        for(int i=1;i<10;i++) q.push(i);
        while(!q.empty()){
            ll x = q.front();
            q.pop();
            if(len(x)==n){
                if(s.find((int)x)==s.end()){
                    ans.push_back((int)x);
                    s.insert((int)x);
                }
                continue;
            } 
            int d = x%10;
            if(d+k<=9) q.push(x*10+d+k);
            if(d-k>=0) q.push(x*10+d-k);
        }
        return ans;
    }
};