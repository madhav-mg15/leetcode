int m,n;
class Solution {
public:
    bool check(vector<vector<int>>& mat){
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(mat[i][j]) return false;
        return true;
    }
    bool isValid(int i, int j){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int minFlips(vector<vector<int>>& mat) {
        int ans=1e8;
        m=mat.size(), n=mat[0].size();
        set<vector<vector<int>>> s;
        queue<pair<int,vector<vector<int>>>> q;
        q.push({0,mat});
        s.insert(mat);
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int mvs=x.first;
            mat = x.second;
            if(check(mat)) return mvs;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    vector<vector<int>> v=mat;
                    v[i][j]=1-v[i][j];
                    for(int d=0;d<4;d++){
                        int nr=i+dir[d][0], nc=j+dir[d][1];
                        if(isValid(nr,nc)) v[nr][nc]=1-v[nr][nc];
                    }
                    if(s.find(v)==s.end()){
                        s.insert(v);
                        q.push({mvs+1,v});
                    }
                }
            }
        }
        return -1;
    }
};