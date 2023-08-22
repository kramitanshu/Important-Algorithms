// prime factorisation

#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
vector<int> spf(N);

void createSeive(){
	for(int i = 0; i<N; i++){
		spf[i] = i;
	}

	for(int i = 2; i*i<=N; i++){
		if(spf[i] == i){

			for(int j = 2*i; j <= N;j+=i ){
				if(spf[j] == j){
					spf[j] = i;
				}

			}
		}
	}
}

int main(){

	// n log (log n)
	createSeive();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		while(n != 1){
			cout << spf[n] << " ";
			n/=spf[n];
		}
		cout << endl;
	}
}