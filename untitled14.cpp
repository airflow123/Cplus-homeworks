#include<bits/stdc++.h>
using namespace std;
vector<int> value(260);
vector<int> winner(260);
void dfs(int x,int n){
	if(x>=1<<n){
		return;
	}
	dfs(x*2,n);
	dfs(x*2+1,n);
	if(value[x*2]>value[x*2+1]){
		value[x]=value[x*2];
		winner[x]=winner[x*2];
	}else{
		value[x]=value[x*2+1];
		winner[x]=winner[x*2+1];
	}
}
int main()
{	
	int n;
	cin>>n;
	for(int i=0;i<(1<<n);i++){
		cin>>value[(1<<n)+i];
		winner[(1<<n)+i]=i+1;
	}
	dfs(1,n);
	cout<<((value[2]>value[3])?winner[3]:winner[2])<<endl;
	
	return 0;
}
