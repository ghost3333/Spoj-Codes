#include <bits/stdc++.h>
using namespace std;
 
int findset(int x, vector <int> &par){
	if (par[x] != x) par[x] = findset(par[x], par);
	return par[x];
}
 
void unionit(int x, int y, vector <int> &par, vector <int> &rank){
	int s1 = findset(x, par);
	int s2 = findset(y, par);
 
	if (rank[s1] > rank[s2]) par[s2] = s1;
	else par[s1] = s2;
 
	if (rank[s1] == rank[s2]) rank[s2] += 1;
}
 
int main(){
	int t;
	cin >> t;
 
	while (t--){
		int n;
		cin >> n;
 
		vector <int> par(n);
		for (int i = 0; i < n; i++) par[i] = i;
 
		vector <int> rank(n, 0);
 
		vector <vector <long long>> edges;
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
 
			int q;
			cin >> q;
			for (int j = 0; j < q; j++){
				long long r, c;
				cin >> r >> c;
				if (r-1 > i){
					vector <long long> nv(3);
					nv[0] = c;
					nv[1] = i;
					nv[2] = r-1;
					edges.push_back(nv);
				}
			}
		}
 
		long long ans = 0;
		sort(edges.begin(), edges.end());
		for (vector <long long> ele : edges){
			int s1 = findset(ele[1], par);
			int s2 = findset(ele[2], par);
			if (s1 != s2){
				ans += ele[0];
				unionit(s1, s2, par, rank);
			}
		} 
		cout << ans << endl;
 
	}
	return 0;
} 