class Solution {
public:
    int m,n;
    vector<vector<int>> heights;
    void dfs(int i,int j,vector<vector<bool>>& visited){
        visited[i][j]=true;
        int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        for(auto& d:dirs){
            int ni=i+d[0];int nj=j+d[1];
            if(ni<0||ni>=m||nj<0||nj>=n)continue;
            if(visited[ni][nj])continue;
            if(heights[ni][nj]<heights[i][j])continue;
            dfs(ni,nj,visited);

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        heights =h;
        m=h.size();n=h[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            dfs(i,0,pacific);
            dfs(i,n-1,atlantic);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,pacific);
            dfs(m-1,i,atlantic);
        }
        vector<vector<int>> result;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};