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

int main() {

	int n;
	while (cin >>n && n)
	{
		int k = ceil(sqrt(n));
        int x, y;
        if (k % 2)
            x = 1, y = k;
        else
            x = k, y = 1;
        ll sq = 1LL * k * k;
        ll corner = (1LL*k - 1) * (k - 1) + 1;
        ll corner2 = corner + k - 1;
        if (k % 2) {
            if (n >= corner2)
                x += sq - n;
            else
                x += k - 1, y -= (corner2 - n);
        }
        else {
            if (n >= corner2)
                y += sq - n;
            else
                y += k - 1, x -= (corner2 - n);
        }
        cout << x << " " << y << endl;


	}
	
}
