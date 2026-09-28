unordered_map<string,int> m;
bool cmp(string &a, string &b){
    if(m[a]==m[b]) return a<b;
    return m[a]<=m[b];
}
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        m = unordered_map<string,int> ();
        vector<int> vis(101,0);
        vis[id]=1;
        queue<pair<int,int>> q;
        q.push({id,0});
        while(!q.empty()){
            id = q.front().first; 
            int lev=q.front().second;
            q.pop();
            if(lev==level){
                for(string &st : watchedVideos[id]) m[st]++;
                continue;
            }
            for(auto x:friends[id]){
                if(!vis[x]){
                    q.push({x,lev+1});
                    vis[x]=1;
                }
            }
        }
        vector<string> ans;
        for(auto x:m) ans.push_back(x.first);
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};