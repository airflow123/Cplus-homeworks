#include<bits/stdc++.h>
using namespace std;
const int MAXT=1e9;


int main()
{
	int n;
	cin>>n;
	int maxA=0;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxA=max(maxA,a[i]);
	}
	vector<int>best(n+1,MAXT);
	vector<int>nxt(maxA+1);
	vector<int>spf(maxA+1);
	for(int i=2;i<=maxA;i++){
		if(spf[i]==0){
			spf[i]=i;
			for(long long j=1LL*i*i;j<=maxA;j+=i){
				if(spf[j]==0)spf[j]=i;
			}
		}
	}
	for(int i=n;i>0;i--){
		int x=a[i];
		int mn=MAXT;
		while(x>1){
			int p=spf[x];
			if(nxt[p]!=0){
				mn=min(mn,nxt[p]);
			}
			while(x%p==0)x/=p;
		}
		best[i]=mn;
		x=a[i];
		while(x>1){
			int p=spf[x];
			nxt[p]=i;
			while(x%p==0)x/=p;
		}
	}
	for(int i=1;i<=n;i++){
		if(best[i]!=MAXT){
			cout<<i<<" "<<best[i]<<endl;
			return 0;
		}
	}
	return 0;
}
