class Solution
{
public:
  bool f(int node, vector<int> adj[], vector<int> &vis, vector<int> &inrecur)
  {
    vis[node] = 1;
    inrecur[node] = 1;

    for (auto neigh : adj[node])
    {
      if (vis[neigh] == 1 and inrecur[neigh] == 1)
      {
        return true;
      }

      else
      {
        if (vis[neigh] == 0)
          if (f(neigh, adj, vis, inrecur))
          {
            return true;
          }
      }
    }
    inrecur[node] = 0;
    return false;
  }

  bool canFinish(int n, vector<vector<int>> &pre)
  {
    vector<int> adj[n];
    for (auto x : pre)
    {
      int from = x[1];
      int to = x[0];
      adj[from].push_back(to);
    }
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == 0)
      {
        vector<int> inrecursion(n, 0);
        if (f(i, adj, vis, inrecursion) == true)
        {
          return false;
        }
      }
    }
    return true;
  }
};
