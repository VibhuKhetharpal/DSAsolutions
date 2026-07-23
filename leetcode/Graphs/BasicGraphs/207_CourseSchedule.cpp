class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto prerequisite:prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<bool> visit(numCourses);
        vector<bool> inStack(numCourses);

        for(int i=0;i<numCourses;i++){
            if(dfs(i,adj,visit,inStack)){
                return false;
            }
        }
        return true;
        
    }
    bool dfs(int i,vector<vector<int>>& adj,vector<bool>& visit,vector<bool>& inStack){
        if(inStack[i])return true; //dfs detects cycle;
        if(visit[i])return false;

        visit[i]=true;
        inStack[i]=true;
        for(auto& neighbor:adj[i]){
            if(dfs(neighbor,adj,visit,inStack)){
                return true;
            }
        }
        inStack[i]=false;
        return false;


    }
};