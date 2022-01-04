#split wise algorithm implementation.
#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define mod 998244353
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define ll long long
#define inf 9000000000000000000
#define PI 3.14159265359

int power(int a, int b, int m = mod)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int res = power(a, b / 2, m);
    res = (res * res) % m;
    if (b & 1)
        res = (res * a) % m;
    return res;
}
int modinv(int a, int m = mod) { return power(a, m - 2, m); }
int add(int a, int b, int m = mod)
{
    int c = (a % m + b % m);
    if (c >= m)
        c -= m;
    return c;
}
int sub(int a, int b, int m = mod)
{
    int c = (a % m - b % m);
    if (c < 0)
        c += m;
    return c;
}
int mul(int a, int b, int m = mod) { return (a * b) % m; }

int32_t main()
{
    IOS

        int no_of_transactions,
        no_of_friends, i;
    cin >> no_of_transactions >> no_of_friends;

    map<string, int> net;

    for (i = 0; i < no_of_transactions; i++)
    {
        string x, y;
        int amount;
        cin >> x >> y >> amount;

        if (net.count(x) == 0)
        {
            net[x] = 0;
        }
        if (net.count(y) == 0)
        {
            net[y] = 0;
        }
        net[x] = net[x] - amount;
        net[y] = net[y] + amount;
    }
    multiset<pair<int, string>> s;

    for (auto p : net)
    {
        string person = p.first;
        int amount = p.second;

        if (net[person] != 0)
        {
            s.insert({amount, person});
        }
    }
    int min_transactions = 0;

    while (!s.empty())
    {
        auto low = s.begin();
        auto high = prev(s.end());

        int debit = low->first;
        string debit_person = low->second;

        int credit = high->first;
        string credit_person = high->second;

        s.erase(low);
        s.erase(high);

        int settle_amount = min(-debit, credit);
        debit = debit + settle_amount;
        credit = credit - settle_amount;
        if (debit != 0)
        {
            s.insert({debit, debit_person});
        }
        if (credit != 0)
        {
            s.insert({credit, credit_person});
        }
        cout << debit_person << " is gonna pay " << settle_amount << " to " << credit_person << endl;

        min_transactions++;
    }
    cout << min_transactions << endl;
}