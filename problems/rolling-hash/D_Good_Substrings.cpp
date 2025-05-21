#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

const int INF = 2e9,
          INFLL = 1e18;

const int p[3] = {91138233, 97266353, 19260817};
const int mod[3] = {1000000007, 1000000009, 998244353};

struct HASH
{
    size_t operator()(const tuple<int, int, int> &x) const
    {
        auto h1 = hash<unsigned long long>()(get<0>(x));
        auto h2 = hash<unsigned long long>()(get<1>(x));
        auto h3 = hash<unsigned long long>()(get<2>(x));
        return h1 ^ (h2 << 21) ^ (h3 << 42);
    }
};

#define TupleHashSet unordered_set<tuple<int, int, int>, HASH>

struct RollingHash
{
    int base, mod, maxlen;
    vi pow;
    RollingHash(int base, int mod, int maxlen) : base(base), mod(mod), maxlen(maxlen)
    {
        pow.resize(maxlen + 2);
        pow[0] = 1;
        for (int i = 1; i <= maxlen; i++)
        {
            pow[i] = (pow[i - 1] * base) % mod;
        }
    }

    vi calculateHash(const string &s)
    {
        int n = s.size();
        vi hash(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            hash[i] = (hash[i - 1] * base + s[i - 1]) % mod;
        }
        return hash;
    }

    int ssHash(int l, int r, const vi &hash)
    {
        if (l > r)
            throw invalid_argument("ssHash: l > r");
        return (hash[r + 1] - (hash[l] * pow[r - l + 1]) % mod + mod) % mod;
    }
};

void solve()
{
    string s, alp;
    int maxZeroAllowed;

    cin >> s >> alp >> maxZeroAllowed;
    int size = s.size();

    RollingHash hash1(p[0], mod[0], size);
    RollingHash hash2(p[1], mod[1], size);
    RollingHash hash3(p[2], mod[2], size);

    vi h1 = hash1.calculateHash(s);
    vi h2 = hash2.calculateHash(s);
    vi h3 = hash3.calculateHash(s);

    TupleHashSet hashSet;
    hashSet.reserve(size * size + 1);

    for (int i = 0; i < size; i++)
    {
        int currentZeros = 0;
        for (int j = i; j < size; j++)
        {
            if (alp[s[j] - 'a'] == '0')
            {
                currentZeros++;
            }

            if (currentZeros > maxZeroAllowed)
            {
                break;
            }

            int hashVal1 = hash1.ssHash(i, j, h1);
            int hashVal2 = hash2.ssHash(i, j, h2);
            int hashVal3 = hash3.ssHash(i, j, h3);

            hashSet.insert({hashVal1, hashVal2, hashVal3});
        }
    }

    cout << hashSet.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
