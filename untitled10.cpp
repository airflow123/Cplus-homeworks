#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<ll> high(n), shoot(n), store(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> high[i] >> shoot[i];
	}
	
	// 往右：每个 i 的能量给右边第一个比它高的
	stack<int> st;   // 存下标，高度单调递减
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && high[st.top()] <= high[i]) st.pop();
		if (!st.empty()) {
			store[st.top()] += shoot[i];   // 右边第一个更高的接收
		}
		st.push(i);
	}
	
	// 往左：每个 i 的能量给左边第一个比它高的
	while (!st.empty()) st.pop();
	for (int i = 0; i < n; i++) {
		while (!st.empty() && high[st.top()] <= high[i]) st.pop();
		if (!st.empty()) {
			store[st.top()] += shoot[i];   // 左边第一个更高的接收
		}
		st.push(i);
	}
	
	ll maxi = 0;
	for (auto &x : store) maxi = max(maxi, x);
	cout << maxi << endl;
	return 0;
}
