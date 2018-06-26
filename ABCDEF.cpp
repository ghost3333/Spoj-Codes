#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
 
	vector <long long> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
 
	vector <long long> left;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				left.push_back(arr[i]*arr[j] + arr[k]);
			}
		}
	}
 
	vector <long long> right;
	for (int i = 0; i < n; i++){
		if (arr[i] == 0) continue;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				right.push_back(arr[i]*(arr[j] + arr[k]));
			}
		}
	}
 
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
 
	long long ans = 0;
 
	long long i = 0;
	vector <long long> :: iterator lowinleft, highinleft, lowinright, highinright; 
	while (i < left.size()){
 
		lowinleft = lower_bound(left.begin(), left.end(), left[i]);
		highinleft = upper_bound(left.begin(), left.end(), left[i]);
 
		long long leninleft = (highinleft - lowinleft);
 
		lowinright = lower_bound(right.begin(), right.end(), left[i]);
		highinright = upper_bound(right.begin(), right.end(), left[i]);
 
		long long leninright = (highinright - lowinright);
 
		ans += leninleft * leninright;
 
		i += leninleft;
	}
 
	cout << ans << endl;

	return 0;
} 