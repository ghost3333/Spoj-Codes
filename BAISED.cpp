#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
int main(){
	long long t;
	cin >> t;
 
	while (t--){
		long long n;
		cin >> n;
 
		vector <string> name(n);
		vector <long long> wantrank(n);
		for (int i = 0; i < n; i++){
			cin >> name[i] >> wantrank[i];
		}
 
		sort(wantrank.begin(), wantrank.end());
 
		long long res = 0;
		for (int i = 0; i < n; i++) res += abs(wantrank[i] - (i+1));
 
		cout << res << endl;
	}
 	return 0;
} 