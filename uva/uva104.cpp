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
#define MAX 1000000

const double val = 1.01;

double adjMat[21][21][21];
int parent[21][21][21];

int main (){

	int n;
	while (cin>>n)
	{
		memset(adjMat , 0, sizeof adjMat);
		memset(parent , -1 ,sizeof parent);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) {
				if (i==j)
					adjMat[i][i][1]=1;
				else 
					cin >>adjMat[i][j][1];
				parent[i][j][1] = i;
			}
		}

		for(int s=2;s<=n;s++)
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++) {
						if (adjMat[i][j][s] < adjMat[i][k][s-1] * adjMat[k][j][1]) {
							adjMat[i][j][s] = adjMat[i][k][s-1] * adjMat[k][j][1];
							parent[i][j][s] = k;
						}
					}

					bool f = false;
					int ii;
					int edgess;
					for(int s=2;s<=n;s++){
						if(f)
							break;
						for(int i=1;i<=n;i++){
							if (adjMat[i][i][s] > val)
							{
								ii =i;
								edgess=s;
								f = true;
								break;
							}
						}
					}

					if (f){

						cout <<ii;
						int cur = parent[ii][ii][edgess--];
						while (cur != -1)
						{
							cout <<" ";
							cout <<cur;
							cur = parent[ii][cur][edgess--];
						}
						cout <<endl;

					}
					else cout <<"no arbitrage sequence exists"<<endl;



	}

}
