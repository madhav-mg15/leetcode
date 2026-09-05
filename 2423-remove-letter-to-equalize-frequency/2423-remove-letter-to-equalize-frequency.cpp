class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<int,int> m,mp;
        for(int i=0;i<word.length();i++) m[word[i]]++;
        for(auto x:m) mp[x.second]++;
        cout<<mp.size()<<endl;
        if(mp.size()>2) return false;
        if(mp.size() == 1){
            auto x = mp.begin();
            int  k1 = x->first;
            int v1 = x->second;
            cout<<k1<<" "<<v1<<endl;
            if(k1==1 || v1==1) return true;
            else return false;
        }
        if(mp.size() == 2){
            int k1 = 0, v1 = 0, k2 = 0, v2 = 0;
            for(auto x:mp){
                if(k1 == 0 && v1 == 0){
                    k1=x.first;
                    v1=x.second;
                }
                k2 = x.first;
                v2 = x.second;
            }
            cout<<k1<<" "<<v1<<" "<<endl<<k2<<" "<<v2<<endl;
            if(k1>k2){
                swap(k1,k2);
                swap(v1,v2);
            }
            if(k1==1 && v1==1) return true;
            if(k2-k1==1 && v2==1) return true;
            return false;
        }
        return -1;
    }
};