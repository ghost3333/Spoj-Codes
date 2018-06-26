#include <bits/stdc++.h>
using namespace std;
 
struct node{
	long long val;
	vector <node*> neig;
	bool visited = false;
};
 
void bfs(vector <node*> vert, int &clus){
	for (node* ele : vert){
		if (ele->visited == false){
			ele->visited = true;
			clus += 1;
 
			list <node*> s;
			s.push_back(ele);
			while (!s.empty()){
				node* nd = s.front();
				s.pop_front();
 
				for (node* neigele : nd->neig) {
					if (neigele->visited == false){
						s.push_back(neigele);
						neigele->visited = true;
					}
				}
			}
		}
	}
}
 
int main(){
	int t;
	cin >> t;
 
	while (t--){
		int n, m;
		cin >> n >> m;
 
		vector <node*> vert(n);
		for (int i = 0; i < n; i++){
			vert[i] = new node;
			vert[i]->val = i;
		}
 
		for (int i = 0; i < m; i++){
			int l, r; 
			cin >> l >> r;
			vert[l]->neig.push_back(vert[r]);
			vert[r]->neig.push_back(vert[l]);
		}
 
		int clus = 0;
 
		bfs(vert, clus);
 
		cout << clus << endl;
	}
 
	return 0;
} 