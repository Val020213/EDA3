#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vector<int>>

const int INF = 2e9,
          MOD = 1e9 + 7,
          INFLL = 1e18,
          MAXN = 1e5;

struct LCA
{
    int cont;
    vi first, last;
    vvi up;
    int logn;
    vi depth;

    LCA(const int nodes, const vvi &g) : logn(ceil(log2(nodes)))
    {
        cont = 0;
        first.resize(nodes + 1);
        last.resize(nodes + 1);
        up.assign(nodes + 1, vi(logn + 1));
        depth.resize(nodes + 1);

        depth[1] = 0;
        dfs(g, 1, 1);
    }

    void dfs(const vvi &g, int node, int parent)
    {
        cont++;
        first[node] = cont;
        up[node][0] = parent;
        depth[node] = depth[parent] + 1;

        for (int i = 1; i <= logn; i++)
        {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int u : g[node])
        {
            if (u != parent)
            {
                dfs(g, u, node);
            }
        }

        last[node] = cont;
    }

    bool is_ancestor(int u, int v)
    {
        return first[u] <= first[v] && last[u] >= last[v];
    }

    int lca(int u, int v) // bl
    {
        if (is_ancestor(v, u))
        {
            return v;
        }

        if (is_ancestor(u, v))
        {
            return u;
        }

        for (int i = logn; i >= 0; i--)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    int dist(int u, int v)
    {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

void solve()
{
    int nodes, query;
    cin >> nodes >> query;
    vvi g(nodes + 1);

    int u, v;
    for (int i = 1; i < nodes; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCA lca(nodes, g);

    while (query--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = lca.dist(a, b) + lca.dist(c, d);
        int y = min(lca.dist(a, c) + lca.dist(b, d), lca.dist(a, d) + lca.dist(b, c));

        int ans = max(0LL, (x - y) / 2 + 1);

        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
