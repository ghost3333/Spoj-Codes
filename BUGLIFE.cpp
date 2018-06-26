#include <bits/stdc++.h>
using namespace std;
 
struct node{
	int val;
	bool visited = false;
	int col = -1;
	vector <node*> neig;
};
 
bool bfs(vector <node*> vert){
	bool flag = true;
	for (node* ele : vert) {
		if (ele->visited == false) {
			list <node*> s;
			s.push_back(ele);
			ele->visited = true;
			ele->col = 0;
 
			while (!s.empty()) {
				node* newnode = s.front();
				s.pop_front();
 
				int colhere = newnode->col ^ 1;
				for (node* nd : newnode->neig){
					if (nd->visited == true){
						if (nd->col != colhere) return false;
					}
					else {
						s.push_back(nd);
						nd->visited = true;
						nd->col = colhere;
					}
				}
			}
		}
	}
	return flag;
}
 
int main(){
	int t;
	cin >> t;
 
	for (int a0 = 1; a0 <= t; a0++){
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
			vert[l-1]->neig.push_back(vert[r-1]);
			vert[r-1]->neig.push_back(vert[l-1]);
		}
 
		bool flag = bfs(vert);
		cout << "Scenario #" << a0 << ":" << endl;
		if (flag) cout << "No suspicious bugs found!" << endl;
		else cout << "Suspicious bugs found!" << endl;
		
	} 
	return 0;
} 