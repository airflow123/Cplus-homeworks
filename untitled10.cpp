#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<ll> high(n);
	vector<ll> shoot(n);
	vector<ll> store(n);
	for (int i = 0; i < n; i++) {
		cin >> high[i];
		cin >> shoot[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (j + 1 < n && high[i] < high[j + 1]) {
				store[j + 1] += shoot[i];
				break;
			}
		}
		for (int j = i; j >= 0; j--) {
			if (j - 1 >= 0 && high[j - 1] > high[i]) {
				store[j - 1] += shoot[i];
				break;
			}
		}
	}
	ll maxi = 0;
	for (auto&i : store) {
		if (maxi < i)maxi = i;
	}
	cout << maxi << endl;
	return 0;
}
