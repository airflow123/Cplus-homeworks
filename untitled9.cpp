#include<bits/stdc++.h>
using namespace std;

int main()
{
	string op;
	vector<string> opo;

	int port[2001];
	int k=0;
	while(cin>>op&&op!="END"){
			if(op=="NUM") {
				int x;
				cin>>x;
				port[k]=x;
				k++;
			}
			else opo.push_back(op);
	};
	//for(auto &x:opo)cout<<x<<endl;
	int n;
	cin>>n;
	while(n--){
		stack<int> st;	
		int x;
		cin>>x;
		if(x>1e9){
			cout<<"ERROR"<<endl;
			continue;
		}
		st.push(x);
		for(int i=0;i<=k;i++){
			if(port[i]>1e9){
				cout<<"ERROR"<<endl;
				break;
			}
			st.push(port[i]);
		}
	
		for(auto&i:opo){
			if(i=="POP"&&!st.empty()){
				st.pop();
			} else {
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="INV"&&!st.empty()){
				int inv=st.top();
				inv=-inv;
				st.pop();
				st.push(inv);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="DUP"&&!st.empty()){
				st.push(st.top());
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="SWP"&&st.size()>=2){
				int s1,s2;
				s1=st.top();
				st.pop();
				s2=st.top();
				st.pop();
				st.push(s1);
				st.push(s2);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="ADD"&&st.size()>=2){
				int s1,s2;
				s1=st.top();
				st.pop();
				s2=st.top();
				st.pop();
				st.push(s1+s2);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="SUB"&&st.size()>=2){
				int s1,s2;
				s1=st.top();
				st.pop();
				s2=st.top();
				st.pop();
				st.push(s1-s2);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="MUL"&&st.size()>=2){
				int s1,s2;
				s1=st.top();
				st.pop();
				s2=st.top();
				st.pop();
				st.push(s1*s2);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="DIV"&&st.size()>=2){
				int s1,s2;
				s1=st.top();
				st.pop();
				s2=st.top();
				st.pop();
				st.push(1.0*s1/s2);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
			if(i=="MOD"&&st.size()>=2){
				int s1,s2;
				s1=st.top();
				st.pop();
				s2=st.top();
				st.pop();
				st.push(s1%s2);
			}else{
				cout<<"ERROR"<<endl;
				break;
			}
		}
	}
	
	return 0;
	}
