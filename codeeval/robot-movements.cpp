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

bool visited [10][10];
const int DIM = 9;
int calculate(int i, int j) {

    if (visited[i][j])
        return 0;
    if (i == DIM && j == DIM)
        return 1;
    int cnt = 0;
    visited[i][j] = true;
    if (i < DIM)
        cnt += calculate(i + 1, j);
    if (j < DIM)
         cnt += calculate(i, j + 1);
    if (i > 0)
        cnt += calculate(i - 1, j);
    if (j > 0)
        cnt += calculate(i, j - 1);
    visited[i][j] = false;
    return cnt;

}

int main() {
    memset(visited, false, sizeof visited);
    cout << calculate(0, 0) << endl;
}