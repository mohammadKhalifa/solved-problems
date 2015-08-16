
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
int cnt[MAX+1];
int a [100001];
int beg[MAX+1];
int endd[MAX+1];
bool check[MAX+1];
int main(){
	int n; cin >>n;
	for (int i=0;i<n;i++){
		cin >>a[i];
		cnt[a[i]]++;
	}
	int beauty = 0;
	for (int i=0;i<n;i++){
		beauty = max (beauty , cnt[a[i]]);
	}
	for(int i=0;i<n;i++) {
		if (!check[a[i]])
			beg[a[i]] = i , check[a[i]]= true;
	}
	memset(check,0,sizeof check);
	for (int i=n-1;i>=0;i--)
		if (!check[a[i]])
			endd[a[i]] = i , check[a[i]] = true;
	int res=0 , maxSoFar = MAX;
	for(int i=0;i<n;i++){
		int bb =  endd[a[i]] - beg[a[i]];
		if (maxSoFar > bb && beauty == cnt[a[i]]){
			maxSoFar = bb;
			res = a[i];
		}
	}
	cout <<beg[res]+1<< " "<<endd[res]+ 1 <<endl;

}
