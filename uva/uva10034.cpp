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

bool inTree[101];
priority_queue<pair<double,int>> Q;
vector <vector<pair<int,double>>> graph;

void process(int vtx) {
	inTree[vtx] = true;
	for(int i=0;i<graph[vtx].size();i++) {
		pair<int,double> edge = graph[vtx][i];
		int v = edge.first;
		double w = edge.second;
		if(!inTree[v]) 
			Q.push(make_pair(-w,-v));
	}

}
double mstCost() {

	double cost = 0;
	process(0);
	while (!Q.empty())
	{
		pair<double,int> pair = Q.top() ; Q.pop();
		double w = -pair.first ; int u = -pair.second;
		if (!inTree[u]) {
			process(u);
			cost+=w;
		}

	}
	return cost;
}

double distance(double x1,double y1 ,double x2 , double y2) {
	double a = (y2-y1) * (y2-y1);
	double b = (x2-x1) * (x2-x1);
	return sqrt(a + b);
}
vector<double> X , Y;

int main(){
	int T;
	cin >>T;
	bool first = true;
	while (T--)
	{
		if(!first)
			cout <<endl;
		first = false;
		memset(inTree,0,sizeof inTree);
		graph.clear();
		X.clear()  , Y.clear();
		int n; cin >>n;
		graph.resize(n);
		for(int i=0;i<n;i++) {
			double x,y;
			cin >>x>>y;
			X.push_back(x) , Y.push_back(y);
		}
		//create complete graph
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				double x1 = X[i] , y1 = Y[i] , x2 = X[j] , y2 = Y[j];
				double d = distance(x1,y1,x2,y2);
				graph[i].push_back(make_pair(j,d));
				graph[j].push_back(make_pair(i,d));
			}
		}
		cout <<fixed << setprecision(2);
		cout <<mstCost()<<endl;
	}
}