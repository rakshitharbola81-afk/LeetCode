class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        q.push(0);
        int n = graph.size();
        int color[n];
        for(int i=0;i<n;i++)color[i]=-1;
        color[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};