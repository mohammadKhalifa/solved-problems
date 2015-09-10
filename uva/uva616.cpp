
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
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i,k,n) for(int i=k;i<=n;i++)
const int MAX = 1000000;

bool pos (int N , int n) {

	for (int i=0;i<n;i++){
		if (N % n !=1)
			return false;
		N  = N -  N/n - 1;
	}
	return N%n==0;
}

int main (){
	
int N,ans,n;
while (cin >>N && N > -1)
{
	int ans = -1;
	for(n=sqrt(N)+1;n>=2;n--) 
		if (pos(N,n)) {
			ans = max(ans ,n);
		}
	cout <<N<<" "<<"coconuts, ";
	(ans > -1)? (cout <<ans<<" people and 1 monkey\n"): cout <<"no solution\n";

}

	}