#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> Aleft , Aright;
int main (){

    ll n , k;
    cin >>n>>k;
    vector<ll> A(n);
    for (int i=0;i<n;++i) {
        cin >>A[i];
    }
long long ans = 0;
    for(int i=n-1;i>=0;--i)
        Aright[A[i]]++;

    Aright[A[0]]--;
    for(int i=1;i<n;i++) {
        Aleft[A[i-1]]++;
        Aright[A[i]]--;
        int a = A[i];
        if (a%k!=0)
            continue;
        ans+= (1LL * Aleft[a/k] * Aright[a*k]);



    }
    cout <<ans<<endl;
}

