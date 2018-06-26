#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
 
	while (t--){
		int n;
		cin >> n;
 
		vector <long long> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
 
		long long count = 0;
		for (int i = 0; i < n; i++){
			if (arr[i] == 1){
				count += 1;
			}
		}
 
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
 
		n = n - count;
 
		if (n == 2 && arr[n-1] == 2 && arr[n-2] == 3){
			arr[n-1] = 3;
			arr[n-2] = 2;
		}
 
		for (int i = 0; i < count; i++){
			cout << 1 << " ";
		}
		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
} 