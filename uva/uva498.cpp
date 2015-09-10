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

bool takeInput(vi &V) {
    V.clear();
    string s;
    getline(cin, s);
    istringstream is(s);
    int n;
    while (is>>n)
        V.push_back(n);

    return !s.empty();
  
}
int evaluate(const vi& coeff , int x) {
    int curPower = 1;
    int ret = 0;
    for (int i = coeff.size()-1; i >=0; --i) {
        ret += curPower * coeff[i];
        curPower *= x;
    }
    return ret;

}
int main() {
    vi coeff, values;
    while (takeInput(coeff))
    {  
        takeInput(values);
        cout << evaluate(coeff, values[0]);
        for (int i = 1; i < values.size(); ++i) {
            cout << " ";
            cout << evaluate(coeff, values[i]);
        }
        cout << "\n";
    }
        

        


    

}