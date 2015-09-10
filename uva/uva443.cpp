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

string getSuffix(int n) {
    int d1 = n % 10;
    int d2 = n % 100;
    if (d1 == 1 && d2 != 11)
        return "st";
    if (d1 == 2 && d2 != 12)
        return "nd";
    if (d1 == 3 && d2 != 13)
        return "rd";
    return "th";

}
int main() {

    vector<ll> numbers;
    for (int i = 0; pow(2, i) < MAX; i++)
        for (int j = 0; pow(3, j) < MAX; j++)
            for (int k = 0; pow(5, k) < MAX; k++)
                for (int l = 0; pow(7, l) < MAX; l++)
                {
                    ll num = pow(2, i) * pow(3, j) * pow(5, k) * pow(7, l);
                    if (num < 0)
                        numbers.push_back(numeric_limits<long long>::max());
                    else  numbers.push_back(num);
                }
    sort(numbers.begin(), numbers.end());
    int n;
    while (cin >> n && n)
        cout <<"The "<<n<<getSuffix(n) <<" humble number is "<< numbers[n - 1]<<"."<< endl;
    
}

