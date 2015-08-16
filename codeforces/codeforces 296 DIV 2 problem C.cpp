#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int w , h , n;
set<int>::iterator itAfter, itBefore;
int main()
{

    cin >> w >> h >> n;
    set<int> wSections,hSections;
    multiset<int> wLengths , hLengths;
    wSections.insert(w) , wSections.insert(0);
    hSections.insert(0) , hSections.insert(h);
    hLengths.insert(h) , wLengths.insert(w);
    for (int i=0;i<n;++i) {

        char c; int x;
        cin >> c >> x;

        if (c=='H') {

            itBefore = hSections.lower_bound(x);
            itAfter = itBefore--;
            int lengthToBeErased = *itAfter - *itBefore;
            hLengths.erase (hLengths.find(lengthToBeErased));
            hLengths.insert((*itAfter) - x);
            hLengths.insert(x - (*itBefore));
            hSections.insert(x);

        }
        else {


            itBefore = wSections.lower_bound(x);
            itAfter = itBefore--;
            int lengthToBeErased = *itAfter - *itBefore;
            wLengths.erase (wLengths.find(lengthToBeErased));
            wLengths.insert(*itAfter - x);
            wLengths.insert(x - *itBefore);
            wSections.insert(x);
            }
            cout << 1LL * (*wLengths.rbegin()) * (*hLengths.rbegin()) <<endl;
    }


        return 0;
}

