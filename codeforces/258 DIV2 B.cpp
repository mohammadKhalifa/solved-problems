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
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

#define MOD 1000000007
int a[100001];
bool IsSorted(int *arr , int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>a[i];

    int x ,y ;
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1]) {x = i; break;}
        int i;
        for(i=x;i<n;i++)
            if(a[i] <a[i+1]) {y=i;break;}
        if(i==n) y = n;

        reverse(a+x , a+y+1);
        if(IsSorted(a,n))
        {
            cout <<"yes"<<endl;
            cout <<x <<" "<<y<<endl;
        }
        else cout <<"no"<<endl;



}