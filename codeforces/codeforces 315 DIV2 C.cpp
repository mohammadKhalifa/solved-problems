/*
ID: skyypol1
PROG: beads
LANG: C++11             
*/
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
const int MAX = 3000000;

bool sieve[MAX+1];
int pi[MAX];
int rub[MAX];
bool isPalindrome(int n) {
	
	int num = n;
	int rev=0;
	while (num > 0)
	{
		int dig = num % 10;
		rev = rev * 10 + dig;
		num = num /10;
	}
	return n==rev;
}

void Sieve(int limit) {

	sieve[1] = true;
	for(int i=4;i<=limit;i+=2)
		sieve[i] = true;

	for(int i=3;i<=sqrt(1.0*limit);i+=2)
		if (!sieve[i])
			for(int j=i*i;j<=limit;j+= 2*i)
				sieve[j] = true;
}



int main(){

	int p,q;
	cin >>p>>q;
	double A = 1.0*p/q;

	Sieve(MAX);
	int curprimes = 0 , curPalindromes = 0;
	for(int n=1;n<=MAX;n++)
	{
		if (!sieve[n])
			++curprimes;
		pi[n] = curprimes;
		if (isPalindrome(n))
			++curPalindromes;
		rub[n] = curPalindromes;
	}

	for(int n=MAX;n>=1;--n) {

		double a = 1.0*pi[n]/rub[n];
		if(a <=A) {
			printf("%d\n",n);
			break;
		}
	}

	//cout <<"Palindromic tree is better than splay tree"<<endl;

	
}