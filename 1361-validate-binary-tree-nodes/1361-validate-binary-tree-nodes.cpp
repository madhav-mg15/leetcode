class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n==1){
            if(leftChild[0] == -1 && rightChild[0] == -1) return true;
            if(leftChild[0] == -1 || rightChild[0] == -1) return false;
            return false;
        }
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) s.insert(leftChild[i]);
            if(rightChild[i]!=-1) s.insert(rightChild[i]);
        }        
        queue<int> q;
        for(int i=0;i<n;i++) if(s.find(i)==s.end()) if(leftChild[i]!=-1 || rightChild[i]!=-1) q.push(i);
        if(q.size()==0 || q.size()>1) return false;
        vector<bool> vis(n,false);
        vis[q.front()] = true;
        cout<<q.front();
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            if(leftChild[ele]!=-1){
                if(vis[leftChild[ele]]) return false;
                q.push(leftChild[ele]);
                vis[leftChild[ele]]=true;
            }
            if(rightChild[ele]!=-1){
                if(vis[rightChild[ele]]) return false;
                q.push(rightChild[ele]);
                vis[rightChild[ele]]=true;
            }
        }
        for(auto x:vis) if(!x) return false;
        return true;
    }
};