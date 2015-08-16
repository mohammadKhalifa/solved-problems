#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;
typedef vector<int> vi;
class CreatePairs {
public :z
    int maximalSum (vector<int> data) {
            vi positive , negative;
            int ones=0 , zeros=0;
            for (int i : data) {

                if (i==0)
                    zeros++;
                if (i==1)
                    ones++;
                if (i > 1)
                    positive.push_back(i);
                if (i < 0)
                    negative.push_back(i);
            }
            if (positive.size() % 2)
                positive.push_back(1); // just a placeholder
            if (negative.size() % 2)
                if(zeros)
                    negative.push_back(0);
                 else negative.push_back(1);

            sort(positive.rbegin(),positive.rend());
            sort(negative.rbegin(),negative.rend());
            int ans = ones;
            for(int i=0;i<positive.size();i+=2)
                ans += positive[i]*positive[i+1];
            for(int j=0;j<negative.size();j+=2)
                ans+=negative[j]*negative[j+1];

            return ans;
       }
};
int main (){
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);

    CreatePairs cp;
    cout <<cp.maximalSum(v)<<endl;

}

