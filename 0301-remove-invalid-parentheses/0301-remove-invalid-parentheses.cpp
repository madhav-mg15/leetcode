vector<set<string>> ans;
string s;
int n;
class Solution {
public:
    void f(int i, int d, string st, int bal){
        if(bal<0 || bal>=11) return;
        if(i==n){
            if(bal==0) ans[d].insert(st);
            return;
        }
        if(s[i]=='('){
            f(i+1,d,st+'(',bal+1);
            f(i+1,d+1,st,bal);
        } 
        else if(s[i]==')'){
            f(i+1,d,st+')',bal-1);
            f(i+1,d+1,st,bal);
        }
        else f(i+1,d,st+s[i],bal);
    }
    vector<string> removeInvalidParentheses(string s1) {
        s = s1;
        n = s.length();
        ans = vector<set<string>> (25);
        f(0,0,"",0);
        vector<string> v;
        for(auto x:ans){
            if(x.size()>0){
                for(auto st:x) v.push_back(st);
                break;
            }
        }
        return v;
    }
};