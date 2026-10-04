#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> q(n);
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(gcd(q[i],q[j])!=1){
				cout<<i+1<<" "<<j+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
