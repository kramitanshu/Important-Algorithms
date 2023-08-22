// GCD


#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}


int main(){

	cout << gcd(4,12) << endl;
	cout << gcd(12,18) << endl;
	cout << gcd(18,12) << endl;
}