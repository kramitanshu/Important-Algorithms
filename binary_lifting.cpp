#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
int up[200001][20];

void binary_lifting(int src, int par){
	up[src][0] = par;

	// Calculation for parent
	for(int i = 1; i<20; i++){
		if(up[src][i-1] != -1){
			up[src][i] = up[up[src][i-1]][i-1]; // recursive call
		}else{
			up[src][i] = -1;
		}
	}

	// Calculation for child
	for(int child: tree[src]){
		if(child != par){
			binary_lifting(child, src);
		}
	}
}

int ans_query(int node, int jump_required){
	if(node == -1 || jump_required == 0){
		return node;
	}

	for(int i = 19; i>= 0; i--){
		if(jump_required >= (1<<i)){
			return ans_query(up[node][i], jump_required - (1<<i));
		}
	}
}

int main(){


}