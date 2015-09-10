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

template<class T, class U> class C {
public: 
    void f() {
        cout << "Primary template" << endl;
    }
};

template <class U> class C<int, U> {
public:
    void f() { cout << "T = int\n"; }
};

template<class T> class C<T, double> {
public:
    void f() { cout << "U == double\n"; }
};

int computeDiagonal(int n) {
    ll sum = 0;

    for (int i = 1; i; ++i) {
        sum = (i*(i + 1))/ 2;
        if (sum >= n)
            return i;
    }
}
int main() {
   
    int n; 
    while (cin >>n)
    {
        int diagonal = computeDiagonal(n); 
        int num, den;
        int a = (diagonal*(diagonal + 1)) / 2 - n;

        if (diagonal % 2 == 0)
            num = diagonal - a;
        else num = 1 + a;

        den = diagonal + 1 - num;
        cout << "TERM " << n << " IS " << num << "/" << den << endl;
    }
}