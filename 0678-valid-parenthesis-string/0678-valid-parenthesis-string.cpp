vector<vector<int>> dp;
string s;
int n;
class Solution {
public:
    bool f(int i, int bal){
        if(i>=n || bal<0 || bal>=51) return false;
        if(i==n-1){
            if(s[i]==')'){
                bal--;
                return bal==0;
            }
            return bal<=1;
        }
        if(dp[i][bal]!=-1) return dp[i][bal];
        bool ans = false;
        if(s[i]=='(') ans |= f(i+1,bal+1);
        else if(s[i]==')') ans |= f(i+1,bal-1);
        else ans = ans | f(i+1,bal+1) | f(i+1,bal-1) | f(i+1,bal);
        return dp[i][bal] = ans;
    }
    bool checkValidString(string s1) {
        s = s1;
        n = s.length();
        if(s[n-1]=='(' || s[0]==')') return false;
        dp = vector<vector<int>>(n, vector<int>(51,-1));
        return f(0,0);
    }
};