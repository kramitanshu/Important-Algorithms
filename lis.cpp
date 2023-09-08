#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define endl "\n"

void display(vi arr){
	for(auto it: arr){
		cout << it << " ";
	}
	cout << endl;
}

void longest_Increasing_subsequence(vi &arr, vi &dp){
	int n = arr.size();
	dp[0] = 1;
	int omax = 1;
	for(int i = 1; i<n; i++){
		int tmax = 0;
		for(int j = 0; j<i; j++){
			if(arr[j] < arr[i]){
				tmax = max(tmax, dp[j]);
			}
		}

		dp[i] = tmax + 1;
		omax = max(omax, dp[i]);
	}
	// display(dp);
	cout << omax << endl;
}
void longest_Decreasing_subsequence(vi &arr, vi &dp){
	int n = arr.size();
	dp[0] = 1;
	int omax = 1;
	for(int i = 1; i<n; i++){
		int tmax = 0;
		for(int j = 0; j<i; j++){
			if(arr[j] > arr[i]){
				tmax = max(tmax, dp[j]);
			}
		}

		dp[i] = tmax + 1;
		omax = max(omax, dp[i]);
	}
	// display(dp);
	cout << omax << endl;
}

int main(){
	int n;
	cin >> n;
	vi arr;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}

	vi dp(n, 0);
	int omax = 0;
	longest_Increasing_subsequence(arr, dp);
	longest_Decreasing_subsequence(arr, dp);

}