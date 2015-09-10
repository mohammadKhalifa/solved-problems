#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int cntBits (int n) {
	int cnt = 0;
	while (n) {
		if (n&1)
			cnt++;
		n >>=1;
	}
	return cnt;


}
string toBinary(int n) {
	
	string ret;
	while (n) {
		if (n&1)
			ret = "1"+ret;
		else ret = "0" + ret;
		n>>=1;
	}
	return ret;

}
int main(){


	int n;
	while(cin >>n && n) {
		
		printf("The parity of %s is %d (mod 2).\n",toBinary(n).c_str(),cntBits(n));


	}	




}