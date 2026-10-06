class Solution {
public:
    int minAddToMakeValid(string s) {
        int a1=0,a2=0;
        for(char &ch:s){
            if(ch=='(') a1++;
            else{
                if(a1!=0) a1--;
                else a2++;
            }
        }
        return a1+a2;
    }
};