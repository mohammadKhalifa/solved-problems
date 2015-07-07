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
#define MAX 2e9

int N , R;
int minEdge;
int graph[101][101];
vector<pair<int, ii> > edges;
vector<bool> visited(101);

void clr(){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			graph[i][j]=0;
}
void dfs(int source) {

	visited[source] = true;
	for(int v=1;v<=N;v++) {
		if(graph[source][v] && !visited[v]){
			dfs(v);
		}
	}
}

int main(){
	int cnt=1;
	while (cin>>N>>R){

		if(N==0)
			break;

		edges.clear();
		clr();
		for(int i=1;i<=R;i++) {
			int c1,c2,w;
			cin >>c1>>c2>>w;
			edges.push_back(make_pair(w,make_pair(c1,c2)));
			graph[c1][c2] = w;
			graph[c2][c1] = w;
		}
		
		int S ,D ,T;
		cin >>S>>D>>T;
		if(S==D){
			cout <<"Scenario #"<<cnt++<<endl;
			cout <<"Minimum Number of Trips = 0"<<endl<<endl;
			continue;
		}
		sort(edges.begin(),edges.end());
		int e=0;
		while (1)
		{
			//remove min edge
			minEdge =edges[e].first;
			ii edge = edges[e].second;
			graph[edge.first][edge.second] = 0;
			graph[edge.second][edge.first] = 0;
			e++;
			fill(visited.begin(),visited.end(),0);
			dfs(S);
			if(!visited[D])
				break;
		}
		int res = ceil(1.0*T/(minEdge-1));
		cout <<"Scenario #"<<cnt++<<endl;
		cout <<"Minimum Number of Trips = "<<res<<endl<<endl;
	}




}
