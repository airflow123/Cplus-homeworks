#include<bits/stdc++.h>
using namespace std;
int main()
{
	string op;
	vector<string> opo;
	
	while(cin>>op&&op!="END"){
			opo.push_back(op);
	};
	for(auto x:opo)cout<<x<<endl;
	
	return 0;
}
