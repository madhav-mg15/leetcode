// using pi = pair<int,int>;
// static bool cmp(pi &a, pi &b){
//     if(a.first==b.first) return a.second<b.second;
//     return a.first<b.first;
// }
class Solution {
public:
    // bool check(vector<pi>& a, vector<pi>& b){
    //     sort(a.begin(),a.end(),cmp);

    // }
    bool f(vector<int>& a){
        int c=0, n=a.size();
        for(int i=0;i<n;i++){
            if((a[i]>a[(i+1)%n])){
                if(c==0) c=1;
                else return false;
            }
        }
        return true;
    }
    bool sorted(vector<int>& a){
        for(int i=0;i<a.size()-1;i++) if(a[i]>a[i+1]) return false;
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> v;
        v.push_back(1);
        for(int i=2;i<=n;i++) if(n%i==0) v.push_back(i);
        if(sorted(nums)) return accumulate(v.begin(),v.end(),0);
        for(int it=0;it<v.size();it++){
            int k = v[it], g = 0;
            vector<int> chk;
            for(int i=0;i<n;i+=k){
                vector<int> a;
                for(int j=0;j<k;j++) a.push_back(nums[i+j]);
                if(f(a)){
                    sort(a.begin(),a.end());
                    for(int &x:a) chk.push_back(x);
                }
                else{
                    g=1;
                    break;
                }
                
            }
            if(g==1) continue;
            if(sorted(chk)) ans+=k;
        }
        return ans;
    }
};