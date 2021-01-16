#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fl(i, a, b) for (int i = a; i < b; i++)
#define dy(a, n) int *a = new int[n]
#define mii map<int, int>
#define vec(a) vector<a>
#define MAXN 1004
#define endl "\n"
#define mod 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n"

int curr = 1, arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int __gcd(int a, int b)
{
    if (b > a)
    {
        swap(a, b);
    }
    return gcd(a, b);
}

int lcm(int a, int b)
{
    int lcm1 = (a / __gcd(a, b)) * b;
    return lcm1;
}

int power(int x, int y)
{
    int res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
        {
            res = res * x;
            res %= mod;
        }
        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
        x %= mod;
    }
    return res;
}

vector<int> primeFactors(int n)
{
    vector<int> ans;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans.push_back(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        ans.push_back(n);
    }
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    string s = "codeforces";
    for (int i = 0; curr < t; i++)
    {
        curr /= arr[i % 10];
        arr[i % 10]++;
        curr *= arr[i % 10];
    }

    for (int i = 0; i < 10; i++)
    {
        while (arr[i])
        {
            cout << s[i];
            arr[i]--;
        }
    }
    cout << endl;
}