int power[26];
class Solution {
public:
    void generate(){
        static bool done = false;
        if(done) return;
        done = true;
        power[0]=1;
        power[1]=2;
        for(int i=2;i<26;i++) power[i]=power[i-1]*2;
        return;
    }
    int scoreOfParentheses(string s) {
        generate();
        int ans=0,cnt=0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch=='(') cnt++;
            else{
                ans+=power[cnt-1];
                int k=i;
                while(k<s.length() && cnt && s[k]==')'){
                    k++;
                    cnt--;
                }
                i=k-1;
            }
        }
        return ans;
    }
};