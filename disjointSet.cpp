#include<bits/stdc++.h>
using namespace std;

// class DisjointSet {
// 	vector<int> rank, parent;
// public:
// 	DisjointSet(int n){
// 		rank.resize(n+1, 0);
// 		parent.resize(n+1);
// 		for(int i = 0; i<=n; i++){
// 			parent[i] = i;
// 		}
// 	}

// 	int findUPar(int node){
// 		if(node == parent[node]){
// 			return node;
// 		}
// 		return parent[node] = findUPar(parent[node]);
// 	}

// 	void unionByRank(int u, int v){
// 		int upu = findUPar(u);
// 		int upv = findUPar(v);

// 		if(upu == upv){

// 		}
// 	}
// };
vector<int> par(10000 + 5);
vector<int> sizes(10000 + 5);

void make(int src){
	par[src] = src;
	sizes[src] = 1;
}

int find(int v){
	if(v == par[v]){
		return v;
	}
	return par[v] = find(par[v]);
}
void Union(int a, int b){
	a = find(a);
	b = find(b);

	if(sizes[a] < sizes[b]){
		swap(a, b);
	}
	par[b] = a;
	sizes[b] = sizes[b] + sizes[a];
}

int main(){
	int n;
	cin >> n;

	for(int i = 0; i<n; i++){
		make(i);
	}

	int e;
	cin >> e;
	while(e--){
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}

	int q;
	cin >> q;
	while(q--){
		int v;
		cin >> v;
		cout <<"Parent of " <<  v << " is: " << par[v] << endl;
	}

	return 0;
}