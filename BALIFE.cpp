#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
 
	while (n != -1){
		vector <long long> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
 
		vector <long long> prefsum(n);
		prefsum[0] = arr[0];
		for (int i = 1; i < n; i++) prefsum[i] = prefsum[i-1] + arr[i];
 
		double avg = (prefsum[n-1] * 1.0)/n;
 
		if (avg != prefsum[n-1] / n){
			cout << -1 << endl;
			cin >> n;
			continue;
		}
		long long iavg = prefsum[n-1] / n;
		vector <long long> actarr(n);
 
		for (int i = 0; i < n; i++) actarr[i] = (i+1)*iavg;
 
		long long maxdiff = -1;
 
		for (int i = 0; i < n; i++) {
			maxdiff = max(maxdiff, abs(actarr[i] - prefsum[i]));
		}
 
		cout << maxdiff << endl;
		cin >> n;
	}
 	return 0;
} 