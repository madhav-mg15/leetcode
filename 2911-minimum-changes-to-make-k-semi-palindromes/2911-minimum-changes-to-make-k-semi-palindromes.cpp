string s;
vector<vector<vector<int>>> dp;
vector<vector<int>> dvv;
vector<vector<int>> v;
class Solution {
public:
    void generate(){
        static bool done = false;
        if(done) return;
        dvv = vector<vector<int>> (211);
        done = true;
        for(int i=1;i<=210;i++){
            if(i==1) continue;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    dvv[i].push_back(j);
                    if(j*j!=i && j!=1) dvv[i].push_back(i/j);
                }
            }
        }
    }
    int f1(int i, int j){
        string st = s.substr(i,j-i+1);
        int n = st.length(), ans=1e8;
        for(int& d:dvv[n]){
            int ch=0;
            for(int x=0;x<d;x++){
                string t="";
                for(int y=x;y<n;y+=d) t+=st[y];
                int l=0, r=t.size()-1;
                while(l<r){
                    if(t[l]!=t[r]) ch++;
                    l++;
                    r--;
                }
            }
            ans=min(ans,ch);
        }
        return ans;
    }
    int f(int i, int j, int k){
        if(j==s.length()-1){
            if(k==1 && j-i+1>=2) return f1(i,j);
            return 1e8;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ntake = (j-i+1>=2 && k>1) ? (v[i][j] + f(j+1,j+1,k-1)) : 1e8;
        int take = f(i,j+1,k);
        return dp[i][j][k] = min(take,ntake);
    }
    int minimumChanges(string s1, int k) {
        generate();
        s = s1;
        int n = s.length();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(k+1,-1)));
        v = vector<vector<int>> (n, vector<int>(n,-1));
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) v[i][j] = f1(i,j);
        return f(0,0,k);
    }
};