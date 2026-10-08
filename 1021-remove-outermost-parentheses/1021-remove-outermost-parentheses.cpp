class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0, idx=0;
        vector<pair<int,int>> v;
        for(int i=0;i<s.length();i++){
            if(cnt==0) idx=i;
            if(s[i]=='(') cnt++;
            else{
                cnt--;
                if(cnt==0) v.push_back({idx,i});
            }
        }
        string st="";
        for(auto x:v) for(int i=x.first+1;i<x.second;i++) st+=s[i];
        return st;
    }
};