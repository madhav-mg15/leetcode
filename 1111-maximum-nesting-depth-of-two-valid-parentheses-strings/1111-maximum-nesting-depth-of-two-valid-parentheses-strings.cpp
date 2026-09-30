class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt =0;
        vector<int> ans;
        for(char x : seq){
            if(x == '(' ){
                cnt++;
                ans.push_back(cnt%2);
            }else{
                ans.push_back(cnt%2);
                cnt--;
            }
        }
        return ans;
    }
};