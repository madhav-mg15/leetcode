int y;
unordered_map<int,int> m;
class Solution {
public:
    int f(int x){
        if(x<y) return y-x; 
        if(x==y) return 0;
        if(m.find(x)!=m.end()) return m[x];
        int ans=abs(x-y);
        if(x%11 == 0) ans=min(ans,f(x/11)+1);
        else ans=min({ans, 11-x%11 +f(x/11 +1)+1, x%11 +f(x/11)+1});
        if(x%5 == 0) ans=min(ans,f(x/5)+1);
        else ans=min({ans, 5-x%5 +f(x/5 +1)+1, x%5 +f(x/5)+1});
        return m[x]=ans;
    }
    int minimumOperationsToMakeEqual(int x, int y1) {
        m.clear();
        y=y1;
        return f(x);
        // queue<pair<int,int>> q;
        // unordered_set<int> s;
        // q.push({x,0});
        // int cnt=0;
        // while(!q.empty()){
        //     int tx=q.front().first, d=q.front().second;
        //     q.pop();
        //     if(tx==y) return d;
        //     if(tx%11 == 0 && s.find(tx/11)==s.end()){
        //         s.insert(tx/11);
        //         q.push({tx/11,d+1});
        //     }
        //     if(tx%5 == 0 && s.find(tx/5)==s.end()){
        //         s.insert(tx/5);
        //         q.push({tx/5,d+1});
        //     }
        //     if(s.find(tx+1)==s.end()){
        //         s.insert(tx+1);
        //         q.push({tx+1,d+1});
        //     }
        //     if(s.find(tx-1)==s.end()){
        //         s.insert(tx-1);
        //         q.push({tx-1,d+1});
        //     }
        //     cnt++;
        // }
        // return -1;
    }
};