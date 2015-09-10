
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

int dist[101][101] , fours[101][101] , seven[101][101];


class LuckyCycle {
public:
	vi getEdge(vi edge1 , vi edge2, vi weight){

		int n = 0;
		for(int i=0;i<edge1.size();++i)
			n = max(n,max(edge1[i],edge2[i]));

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if (i!=j)
				   dist[i][j] = MAX , dist[j][i]=MAX;

		for(int i=0;i<edge1.size();i++){
			int u =edge1[i] , v=edge2[i] , w = weight[i];
			dist[u][v] = w;
			dist[v][u] = w;
			if(w==4)
				fours[u][v]++ ,fours[v][u]++ ;
			else seven[u][v]++ , seven[v][u]++;
		}

		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) {

					int tmp = dist[i][k] + dist[k][j];
					if (dist[i][j] > tmp) {
						dist[i][j] = tmp;
						fours[i][j] = fours[i][k]+fours[k][j];
						seven[i][j] = seven[i][k]+seven[k][j];
					}
				}

		vi ret;
		for (int i=1;i<=n;i++){
			if(!ret.empty())
				break;
			for(int j=1;j<=n;j++) {
				if(dist[i][j]==4 || dist[i][j]==7)
					continue;
				int numEdges = fours[i][j] + seven[i][j];
				if ((numEdges % 2) && abs(fours[i][j] - seven[i][j])==1){
					ret.push_back(i);
					ret.push_back(j);
					int tobeAdded = fours[i][j] > seven[i][j] ? 7 : 4;
					ret.push_back(tobeAdded);
					break;
				}
			}
		}
	return ret;
	}
};



int main(){

	
	int a1[] = {2, 1, 5, 1, 1, 2, 1, 3, 5, 4, 4, 3};
	int a2[] = {13, 2, 7, 5, 3, 12, 4, 11, 6, 9, 8, 10};
	int a3[] =  {4, 7, 7, 4, 7, 4, 4, 4, 7, 7, 7, 4};
	vi edge1(a1,a1+12);
	vi edge2(a2,a2+12);
	vi weight(a3,a3+12);


	
	LuckyCycle lc;
	vi ret = lc.getEdge(edge1,edge2,weight);

}
