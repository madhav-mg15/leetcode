class Solution {
public:
    bool isValid(int i, int j){
        return i>=0 && j>=0 && i<1000000 && j<1000000;
    }
    bool f(vector<vector<int>> blocked, vector<int> source, vector<int> target){
        set<pair<int,int>> s, vis;
        for(auto x:blocked) s.insert({x[0],x[1]});
        if(s.find({source[0],source[1]}) != s.end() || s.find({target[0],target[1]})!=s.end()) return false;
        queue<pair<int,int>> q;
        q.push({source[0],source[1]});
        vis.insert({source[0],source[1]});
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int mx=blocked.size()*blocked.size(), cnt=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int r=x.first, c=x.second;
            if(r==target[0] && c==target[1]) return true;
            if(cnt++>mx) return true;
            for(int d=0;d<4;d++){
                int nr=r+dir[d][0], nc=c+dir[d][1];
                if(isValid(nr,nc) && s.find({nr,nc})==s.end() && vis.find({nr,nc})==vis.end()){
                    q.push({nr,nc});
                    vis.insert({nr,nc});
                }
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return f(blocked,source,target) && f(blocked,target,source);
    }
};