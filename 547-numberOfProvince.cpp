class Solution
{
public:
  void dfs(int node, vector<int> &vis, vector<int> adj[])
  {
    vis[node] = 1;
    for (auto neigh : adj[node])
    {
      if (vis[neigh] == -1)
      {
        dfs(neigh, vis, adj);
      }
    }
  }
  int findCircleNum(vector<vector<int>> &arr)
  {
    int n = arr.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
        {
        }
        else
        {
          if (arr[i][j])
          {
            adj[i].push_back(j);
          }
        }
      }
    }
    int cnt = 0;
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == -1)
      {
        cnt++;
        dfs(i, vis, adj);
      }
    }
    return cnt;
  }
};