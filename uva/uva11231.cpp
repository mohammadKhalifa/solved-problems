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

ll getN(int n) {
    
    if (n < 8)
        return 0;
    return (n - 8) / 2 + 1;

}
int main() {
	int n, m , c;
	while (cin >>n>>m>>c && (n && m))
	{
		
        if (m < 8 || n < 8) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        for (int i = 1; i <= n - 8 + 1; i++)
        {
            if (c)
                ans += getN(m);
            else ans += getN(m - 1);
            c = 1 - c;
        }
        cout << ans << endl;
	}
	
}
