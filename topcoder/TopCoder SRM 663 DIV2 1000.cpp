
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

int numOfSetBits (int n) {
	int cnt=0;
	while (n)
	{
		cnt++;
		n &= (n-1);
	}
	return cnt;
}

int n;
long long dp[16][1<<16];
vector<string> wins;
vector<vector<int>> mask_splits;

long long f(int i , int mask) {
	long long &res  = dp[i][mask];
	if (res!=-1) 
		return res;
	int t = numOfSetBits(mask);
	if (t==1) 
		return 1;
	res = 0;
	for (int mask1:mask_splits[mask]) {
		if(mask & (1<<i)) {
			int mask2 = (mask & ~mask1);

			for (int j=0 ; j<n ; j++ ) {
				if ((wins[i][j]=='Y') && (mask2 & (1<<j)))
					res += 2 * f(i,mask1) * f(j,mask2);
			}
		}
	}
	return res;
}

class CheeseRolling {
public:
	vector<long long> waysToWin(vector<string> win) {
		wins = win;
	   n=wins.size();
		mask_splits.resize(1<<n);
		for (int mask = 1 ; mask < (1<<n);mask++) {
			cout <<mask<<endl;
			for (int subset=(mask-1) & mask; subset > 0 ; subset = (subset - 1) &mask){
				cout <<"     "<<subset<<endl;
				if (2*numOfSetBits(subset)==numOfSetBits(mask))
					mask_splits[mask].push_back(subset);
			}
			}

		memset(dp,-1,sizeof dp);
		vector<long long> res(n);
		for (int i=0;i<n;i++)
			res[i]=f(i,(1<<n)-1);

		return res;
	}
};
int main(){

	CheeseRolling cr;
	vector<string> w ;
	w.push_back("NNEQ");
	w.push_back("YNQW");
	w.push_back("NNEW");
	w.push_back("NYWE");

	cr.waysToWin(w);

}