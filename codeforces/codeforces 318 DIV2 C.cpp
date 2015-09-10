#include <math.h>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <ctime>
#include <assert.h>
#include <fstream>
#include <fstream>
#include <memory>
#include <functional>
#include <iterator>
#include <limits>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i,k,n) for(int i=k;i<=n;i++)
const int MAX = 2000000001;
const double PI = atan(1) * 4;

vi primes;

void sieve(ll limit) {


}

ll gcd(ll a, ll b) {

    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll a[100001];
int main() {

    int n; cin >> n;
    ll GCD;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    GCD = gcd(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        if (GCD == 1)
            break;
        GCD = gcd(GCD, a[i]);
    }
    for (int i = 0; i < n; i++)
        a[i] /= GCD;
    bool can = true;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0)
            a[i] /= 2;
        while (a[i] % 3 == 0)
            a[i] /= 3;
        if (a[i] > 1) {
            can = false;
            break;
        }
    }
    if (can)
        cout << "Yes" << endl;
    else cout << "No" << endl;

    
}