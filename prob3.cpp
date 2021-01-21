#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


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
#define N 30000

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

    map<int, int> m;
    vector<int> ans;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        n = n / 2;
    }
         
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        { 
            if(i%2!=0 && m[i]==0){
                m[i]++;
                ans.push_back(i);
            }
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        if(n%2!=0)
        {
        ans.push_back(n);
        }
    }
    return ans;
}

void player_1()
{
    cout << "FastestFinger" << endl;
}
void player_2()
{
    cout << "Ashishgup" << endl;
}

bool check_prime(int n)
{
    for (int i = 2; i < min(N, n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        int n;
        cin >> n;
        if(n==1)
        {
            player_1();
            continue;
        }
         if(n==2)
          {
          player_2();
          continue;
           }         
           if(n%2!=0)
        {
            player_2();
            continue;
        }
          if(n%2==0){

              if (ceil(log2(n)) == floor(log2(n)))
              {
                  player_1();
                  continue;
                }
         else if(n%4==0)
         {
             player_2();
             continue;
         }
         else if (n % 4 != 0 && check_prime(n / 2))
         {
             player_1();
             continue;
         }
         else if (n % 4 != 0 && !check_prime(n / 2))
         {
             player_2();
             continue;
         }

    }

}
}

