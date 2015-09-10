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

int dp[51][51];

int editDistance(string x, string y) {

    int n = x.size(), m = y.size();
    for (int i = 0; i <= n; i++)
        dp[0][i] = dp[i][0] = i;
    x = "?" + x;
    y = "?" + y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=m; j++) {
            if (x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min (dp[i - 1][j] + 1, dp[i][j - 1] + 1) , dp[i-1][j-1] + 1);
        }
    return dp[n][m];

}

int main() {
  
    string line;
    while (getline(cin , line)) {

        istringstream is(line);
        string pat, text;
        int n;
        is >> pat >> n >> text;
        vector<pair<int, string>> res;
        for (int i = 0; i < text.size() - pat.size() + 1; ++i) {
            string cur = text.substr(i, pat.size());
            int e = editDistance(cur, pat);
            if (e <= n)
                res.push_back(make_pair(e, cur));
        }
        sort(res.begin(), res.end());
        if (res.empty())
            cout << "No match" << endl;
        else {
            cout << res[0].second;
            for (int i = 1; i < res.size(); ++i) {
                cout << res[i].second <<" ";
            
     }
        }

    }
}