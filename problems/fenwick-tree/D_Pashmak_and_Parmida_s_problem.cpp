#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

const int INF = 2e9,
          MOD = 1e9 + 7,
          INFLL = 1e18;

struct Abi
{
    int length;
    vi _abi;

    Abi(int n) : length(n), _abi(n + 1, 0) {}

    int _lowbit(int i) const
    {
        return i & (-i);
    }

    void add(int i, int x)
    {
        for (; i <= length; i += _lowbit(i))
        {
            _abi[i] += x;
        }
    }

    int sum(int i) const
    {
        int s = 0;
        for (; i > 0; i -= _lowbit(i))
        {
            s += _abi[i];
        }
        return s;
    }

    int sum(int l, int r) const
    {
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;

    vi a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vi prefix(n); // f(1, i , ai)
    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++)
    {
        frequency[a[i]]++;
        prefix[i] = frequency[a[i]];
    }

    frequency.clear();

    vi suffix(n); // f(j, n, aj)

    for (int i = n - 1; i >= 0; i--)
    {
        frequency[a[i]]++;
        suffix[i] = frequency[a[i]];
    }

    Abi abi(n);
    for (int j = 0; j < n; j++)
    {
        abi.add(suffix[j], 1);
    }

    // inversiones
    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        abi.add(suffix[i], -1); // quedarnos con el subarray [i, n]
        pairs += abi.sum(prefix[i] - 1);
    }

    cout << pairs << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
