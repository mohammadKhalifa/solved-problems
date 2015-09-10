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
const int MAX = 1000000;
const double PI = atan(1) * 4;
int kl;

char getNthDigit(ll N, int n) {

    string s = to_string(N);
    return s[s.size() - n - 1];

}
int main() {

    int n;
        while (cin >> n)
        {

            ll digitsTillNow = 0;
            int k;
            for (k = 1; k; k++) {
                digitsTillNow += (k * 9 * pow(10, k - 1));
                if (digitsTillNow >= n)
                    break;
            }
            digitsTillNow -= (k * 9 * pow(10, k - 1));
            ll N = pow(10, k - 1);
            while (1) {
                digitsTillNow += k;
                if (digitsTillNow >= n)
                    break;
                N++;
            }
            int dif = digitsTillNow - n;
            cout << getNthDigit(N,dif) << endl;
        }
}
