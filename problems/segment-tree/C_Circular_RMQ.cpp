#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

const int INF = 2e9,
          MOD = 1e9 + 7,
          INFLL = 1e18;

struct SegmentTree
{
    int n;
    vi tree;
    vi lazy;
    SegmentTree(int size, const vi &input) : n(size)
    {
        tree.resize(4 * n, INFLL);
        lazy.resize(4 * n, 0);
        build(0, 0, n - 1, input);
    }

    void build(int node, int left, int right, const vi &input)
    {
        if (left == right)
        {
            tree[node] = input[left];
            lazy[node] = 0;
            return;
        }

        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid, input);
        build(2 * node + 2, mid + 1, right, input);

        lazy[node] = 0;
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void propagate(int node, int left, int right)
    {
        tree[node] += lazy[node];
        if (left != right)
        {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int node, int left, int right, int queryLeft, int queryRight, int increment)
    {
        propagate(node, left, right);

        if (left > queryRight || right < queryLeft)
            return;

        if (left >= queryLeft && right <= queryRight)
        {
            lazy[node] += increment;
            propagate(node, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(2 * node + 1, left, mid, queryLeft, queryRight, increment);
        update(2 * node + 2, mid + 1, right, queryLeft, queryRight, increment);

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int node, int left, int right, int queryLeft, int queryRight)
    {
        if (left > queryRight || right < queryLeft)
            return INFLL;

        propagate(node, left, right);

        if (queryLeft <= left && right <= queryRight)
            return tree[node];

        int mid = (left + right) / 2;
        return min(query(2 * node + 1, left, mid, queryLeft, queryRight),
                   query(2 * node + 2, mid + 1, right, queryLeft, queryRight));
    }
};

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree segTree(n, arr);

    int queries;
    cin >> queries;
    while (queries--)
    {
        string line;
        cin >> ws;
        getline(cin, line);
        stringstream ss(line);
        vector<int> params;
        int value;
        while (ss >> value)
            params.push_back(value);

        if (params.size() == 2)
        {
            if (params[0] > params[1])
            {

                cout << min(segTree.query(0, 0, n - 1, params[0], n - 1),
                            segTree.query(0, 0, n - 1, 0, params[1]))
                     << endl;
            }
            else
            {
                cout << segTree.query(0, 0, n - 1, params[0], params[1]) << endl;
            }
        }

        if (params.size() == 3)
        {
            int left = params[0];
            int right = params[1];
            int increment = params[2];

            if (params[0] > params[1])
            {

                segTree.update(0, 0, n - 1, params[0], n - 1, params[2]);
                segTree.update(0, 0, n - 1, 0, params[1], params[2]);
            }
            else
            {
                segTree.update(0, 0, n - 1, params[0], params[1], params[2]);
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
