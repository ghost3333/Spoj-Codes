#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
    int count = 1;
	while (n){
		map <string, int> dict;
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			dict[s] = i;
		}
 
		vector <vector <double>> dp(n);
		for (int i = 0; i < n; i++){
			vector <double> nv(n, 0);
			dp[i] = nv;
		}
		for (int i = 0; i < n; i++) dp[i][i] = 1;
		int m;
		cin >> m;
		while (m--){
			string st, en;
			double val;
			cin >> st >> val >> en;
			dp[dict[st]][dict[en]] = val;
		}
 
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					dp[i][j] = max(dp[i][j], dp[i][k]*dp[k][j]);
				}
			}
		}        
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (dp[i][i] > 1) {
                flag = true;
                break;
            }
        }
        
        cout << "Case " << count++ << ": ";
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
 
		cin >> n;
	}	
	return 0;
} 