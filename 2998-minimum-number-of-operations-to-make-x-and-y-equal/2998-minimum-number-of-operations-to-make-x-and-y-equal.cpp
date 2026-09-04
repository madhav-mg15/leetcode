class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>> q;
        unordered_set<int> s;
        q.push({x,0});
        int cnt=0;
        while(!q.empty()){
            int tx=q.front().first, d=q.front().second;
            q.pop();
            if(tx==y) return d;
            if(tx%11 == 0 && s.find(tx/11)==s.end()){
                s.insert(tx/11);
                q.push({tx/11,d+1});
            }
            if(tx%5 == 0 && s.find(tx/5)==s.end()){
                s.insert(tx/5);
                q.push({tx/5,d+1});
            }
            if(s.find(tx+1)==s.end()){
                s.insert(tx+1);
                q.push({tx+1,d+1});
            }
            if(s.find(tx-1)==s.end()){
                s.insert(tx-1);
                q.push({tx-1,d+1});
            }
            cnt++;
        }
        return -1;
    }
};