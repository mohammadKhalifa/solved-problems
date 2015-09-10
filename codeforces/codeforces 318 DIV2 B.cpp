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

int degree[4001];
int adjMat[4001][4001];
int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjMat[a][b] = adjMat[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }
    ll res = MAX;
    for (int a = 1; a <= n; a++)
        for (int b = a + 1; b <= n; b++)
                for (int c = b + 1; c <= n; c++)
                    if (adjMat[b][c] && adjMat[a][c] && adjMat[a][b]) // make sure they are all conected
                        res = min(res, 1LL*degree[a] + degree[b] + degree[c] - 6);
    
    res == MAX ? cout << "-1" << endl : cout << res << endl;

}