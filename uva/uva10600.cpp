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
#include <limits>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> ii;
typedef vector<vi> vvi;  
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i,a,b) for(int i=int(a) ; i<=int(b); i++)
//#define s(n)   scanf("%d",&n)
#define INF numeric_limits<long long>::max()
#define ll long long
#define MAX 1e6
vi pset;
void initSet(int N) { 
	pset.assign(N , 0);
	for(int i=0;i<N;i++)
		pset [i] = i;
}
int findSet(int i) {
	return pset[i]==i ? i : (pset[i] = findSet(pset[i]));
}
bool inSameSet(int i ,int j ) {
	return findSet(i) == findSet(j);
}
void unionSet (int i , int j)
{
	pset[findSet(i)] = findSet(j);
}

struct edge {
	int u , v;
	int w;
};
bool cmp(const edge & e1 , const edge & e2) {
	return e1.w < e2.w;
}
int main(){

	int T; cin >>T;
	while (T--)
	{
		vector<edge> edges;
		int n , e;
		cin >>n >>e;
		for (int i=0;i < e;i++) {
			edge E;
			cin >>E.u>>E.v>>E.w;
			edges.push_back(E);
		}
		sort(edges.begin(),edges.end(),cmp);
		int minCost = 0 , minCost2 = MAX;
		vi usedEdges;
		initSet(n+1);
		for (int i=0;i<edges.size();i++) {
			int u = edges[i].u , v = edges[i].v;
			if (!inSameSet(u,v))
			{
				minCost += edges[i].w;
				unionSet(u,v);
				usedEdges.push_back(i);
			}
		}
		
		for (int k=0 ; k < usedEdges.size();k++) {
			initSet(n+1);
			// run Kruskal with edge removed
			int curCost = 0;
			for (int i=0;i<edges.size();i++) {
				if (i== usedEdges[k])
					continue;
				int u = edges[i].u , v = edges[i].v;
				if (!inSameSet(u,v))
				{
					curCost += edges[i].w;
					unionSet(u,v);
				}
			}
			bool cor = true;
				for(int i=1;i<=n;i++)
					for(int j=i+1;j<=n;j++)
						if (!inSameSet(i,j))
							cor = false;
				if (cor)
					minCost2 = min (minCost2 , curCost);

		}

		cout <<minCost <<" "<<minCost2<<endl;
	}

}