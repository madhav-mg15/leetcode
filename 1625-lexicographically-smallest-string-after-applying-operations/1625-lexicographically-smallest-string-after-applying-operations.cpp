class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        int n = s.length();
        string ans = s;
        unordered_set<string> vis;
        vis.insert(s);
        b%=n;
        while(!q.empty()){
            s = q.front();
            q.pop();
            ans = min(ans,s);
            string st = s;
            for(int i=1;i<n;i+=2){
                int d = ((st[i]-'0')+a)%10;
                st[i] = d+'0';
            }
            if(vis.find(st)==vis.end()){
                vis.insert(st);
                q.push(st);
            }
            st = s;
            rotate(st.begin(),st.begin()+b,st.end());
            if(vis.find(st)==vis.end()){
                vis.insert(st);
                q.push(st);
            }
        }
        return ans;
    }
};