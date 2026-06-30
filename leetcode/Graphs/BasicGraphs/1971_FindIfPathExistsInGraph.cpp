class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int node, int destination) {
        if (node == destination)
            return true;

        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        adj.resize(n);
        visited.resize(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(source, destination);
    }
};