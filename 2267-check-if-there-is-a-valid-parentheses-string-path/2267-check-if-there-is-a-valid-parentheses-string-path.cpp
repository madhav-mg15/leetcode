vector<vector<char>> grid;
int m,n;
vector<vector<vector<int>>> dp;
class Solution {
public:
    bool f(int i, int j, int cnt){
        if(i>=m || j>=n || cnt<0 || cnt>=100) return false;
        if(i==m-1 && j==n-1){
            int k = grid[i][j]=='(' ? 1 : -1;
            return cnt+k==0;
        }
        if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];
        int k = grid[i][j]=='(' ? 1 : -1;
        bool right = f(i,j+1,cnt+k);
        bool down = f(i+1,j,cnt+k);
        return dp[i][j][cnt] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid1) {
        grid = grid1;
        m = grid.size(), n = grid[0].size();
        if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;
        dp = vector<vector<vector<int>>> (m, vector<vector<int>>(n, vector<int>(105,-1)));
        return f(0,0,0);
    }
};