#include<bits/stdc++.h>
using namespace std;
struct tree{
	int lefts[1000006]={0};
	int rights[1000006]={0};
}trees;
int dfs(int x){
	if(!x)return 0;
	else{
		int L,R;
			L=dfs(trees.lefts[x]);
			R=dfs(trees.rights[x]);
		return max(L,R)+1;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>trees.lefts[i];
		cin>>trees.rights[i];
	}
	cout<<dfs(1)<<endl;
	
	return 0;
}
