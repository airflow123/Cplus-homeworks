#include<bits/stdc++.h>
using namespace std;
int mgcd(int x,int y){
	if(x%y!=0){
		return mgcd(y,x%y);
	}else{
		return y;
	}
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<mgcd(x,y)<<endl;
	return 0;
}
