
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
const int MAX = 10000001;

int p[MAX];
int cnt1[MAX] , cnt2[MAX];
void pt(vi a, int *cnt) {

	for(int i=0;i<a.size();i++) {
		int prod=1;
		for (int j=a[i];j>1;j/=p[j])
			if (cnt[p[j]])
				cnt[p[j]]--;
			else 
				prod *= p[j];
		cout <<prod<<" ";
	}
	cout <<endl;
}
int main (){
	int n , m;
	cin >> n >> m;
	vi N(n) , D(m);
	for(int i=0;i<n;i++)
		cin >>N[i];
	for(int i=0;i<m;i++)
		cin >>D[i];

	// sieve 
	for(int i=2;i<MAX;i++)
		if (!p[i])
			for(int j=i;j<MAX;j+=i)
				p[j] = i;

	for(int i=0;i<n;i++)
		for(int j=N[i];j>1;j/=p[j])
			cnt1[p[j]]++;

	for(int i=0;i<m;i++)
		for(int j=D[i];j>1;j/=p[j])
			cnt2[p[j]]++;

	cout <<n<<" "<<m<<endl;
	pt(N,cnt2);
	pt(D,cnt1);
}