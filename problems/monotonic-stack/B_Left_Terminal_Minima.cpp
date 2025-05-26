#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

const int INF = 2e9,
          MOD = 1e9 + 7,
          INFLL = 1e18;

void solve()
{
    int test, n;
    cin >> test;

    while (test--)
    {
        cin >> n;

        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        stack<int> monotonic_stack;
        vi left_minima;

        for (int i = 0; i < n; i++)
        {
            while (!monotonic_stack.empty() && monotonic_stack.top() >= v[i])
            {
                monotonic_stack.pop();
            }

            left_minima.push_back(monotonic_stack.size());
            monotonic_stack.push(v[i]);
        }

        for (int i = 0; i < left_minima.size(); i++)
        {
            cout << left_minima[i] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
