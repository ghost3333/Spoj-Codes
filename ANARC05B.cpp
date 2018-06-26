#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	while (n) {
		vector <long long> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int m;
		cin >> m;
		vector <long long> b(m);
		for (int i = 0; i < m; i++) cin >> b[i];

		vector <long long> posina;
		posina.push_back(0);
		vector <long long> posinb;
		posinb.push_back(0);

		for (int i = 0; i < n; i++) {
			vector <long long> :: iterator low, high;

			low = lower_bound(b.begin(), b.end(), a[i]);
			high = upper_bound(b.begin(), b.end(), a[i]);

			if (low != high){
				posina.push_back(i + 1);
				posinb.push_back((low - b.begin()) + 1);
			}
		}

		posina.push_back(n+1);
		posinb.push_back(m+1);

		vector <long long> prefsuma(n+2, 0);
		vector <long long> prefsumb(m+2, 0);

		for (int i = 0; i < n; i++) prefsuma[i+1] = prefsuma[i] + a[i];
		for (int i = 0; i < m; i++) prefsumb[i+1] = prefsumb[i] + b[i];	

		prefsuma[n+1] = prefsuma[n];
		prefsumb[m+1] = prefsumb[m];

		long long ans = 0;
		for (int i = 1; i < posina.size(); i++){
			ans += max(prefsuma[posina[i]] - prefsuma[posina[i-1]], prefsumb[posinb[i]] - prefsumb[posinb[i-1]]);
		}	

		cout << ans << endl;

		cin >> n;
	}
	return 0;
}
