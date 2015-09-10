
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
int a[41];
int pos[41];
int counter;
bool LESS (int a , int b) {
	counter++;
	return pos[a] < pos[b];
}
void mergeSort (int left , int right) {
	if (left >= right-1)
		return;
	int mid = (left+right)/2;
	mergeSort(left,mid);
	mergeSort(mid,right);
	vi merged;
	int p1 = left , p2 = mid;
	while ( (p1 < mid) || (p2 < right))
	{
		if (p1==mid) 
			merged.push_back(a[p2++]);
		else if (p2==right) 
			merged.push_back(a[p1++]);
		else 
			if (LESS (a[p1],a[p2])) 
				merged.push_back(a[p1++]);
			else merged.push_back(a[p2++]);
	}
	for(int i=left;i<right;i++)
		a[i] = merged[i-left];
}

class BearSortsDiv2 {
	double getProbability(vi seq) {
		int n = seq.size();
		for(int i=0;i<n;i++) {
			pos[seq[i]] = i;
			a[i]=i+1;
		}
		mergeSort(0,n);
		return log(0.5) * counter;
	}
};