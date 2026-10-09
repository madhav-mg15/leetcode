class Solution {
public:
    int minInsertions(string s) {
        int n = s.length(), cnt=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(i+1<n){
                    if(s[i]!=s[i+1]){
                        if(st.empty()) cnt+=2;
                        else{
                            cnt++;
                            st.pop();
                        }
                    }
                    else{
                        if(st.empty()) cnt++;
                        else st.pop();
                        i++;
                    }
                }
                else{
                    if(!st.empty()){
                        cnt++;
                        st.pop();
                    }
                    else cnt+=2;
                }
            }
        }
        return cnt + (2*st.size());
    }
};