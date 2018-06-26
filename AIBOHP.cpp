#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin >> t;
 
	while (t--){
		string s;
		cin >> s;
 
		vector <char> arr(s.begin(), s.end());
		int n = arr.size();
		vector <vector <long long>> dp(n+1);
		for (int i = 0; i <= n; i++){
			vector <long long> newvec(n+1, 0);
			dp[i] = newvec;
		}
 
		for (int i = 1; i < n; i++){
			if (arr[i-1] != arr[i]) dp[i][i+1] = 1;
		} 
 
		for (int len = 3; len <= n; len++){
			for (int stind = 1; stind <= n - len + 1; stind++){
				int endind = stind + len - 1;
				if (arr[stind - 1] == arr[endind - 1]) dp[stind][endind] = dp[stind + 1][endind - 1];
				else dp[stind][endind] = min(min(1 + dp[stind+1][endind], 1 + dp[stind][endind - 1]), 2+dp[stind+1][endind-1]);
			}
		}
 
		cout << dp[1][n] << endl;
	}
	return 0;
} 