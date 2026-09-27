class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto x:knowledge) m[x[0]]=x[1];
        string st="";
        int n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z') st+=s[i];
            else if(s[i]=='('){
                int k=i+1;
                string a="";
                while(k<n && s[k]>='a' && s[k]<='z') a+=s[k++];
                if(m.find(a)!=m.end()) st.append(m[a]);
                else st+='?';
                i=k;
            }
        }
        return st;
    }
};