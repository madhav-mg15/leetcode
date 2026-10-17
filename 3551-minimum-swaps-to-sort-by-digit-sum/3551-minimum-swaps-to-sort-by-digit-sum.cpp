bool cmp(vector<int> &a, vector<int> &b){
    int n=a[0], s1=0,s2=0;
    while(n){
        s1+=n%10;
        n/=10;
    }
    n=b[0];
    while(n){
        s2+=n%10;
        n/=10;
    }
    return s1==s2 ? (a[0]<b[0]) : (s1<s2);
}
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++) v[i] = {nums[i],i};
        sort(v.begin(),v.end(),cmp);
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()){
                int k=i;
                while(s.find(k)==s.end()){
                    s.insert(k);
                    k=v[k][1];
                }
                cnt++;
            }
        }
        return n-cnt;
    }
};