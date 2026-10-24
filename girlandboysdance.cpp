#include<bits/stdc++.h>
using namespace std;
struct item{
	int diff;
	int l,r;
	bool operator <(const item& other)const{
		if(diff!=other.diff){
			return diff>other.diff;
		}	
		return l>other.l;
		
	}
}items;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	priority_queue<item> pq;
	vector<int> pre(n+2);
	vector<int> nxt(n+2);
	vector<bool> deleted(n+1,false);
	vector<pair<int,int>>ans;
	auto addpair=[&](int l,int r){
		if(l>0&&r<n+1&&!deleted[l]&&!deleted[r]){
			if(s[l]!=s[r]){
				if(nxt[l]==r&&pre[r]==l){
					return pq.push({abs(a[l]-a[r]),l,r});
				}
			}
		}
	};
	for(int i=1;i<=n;i++){
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	for(int i=1;i<=n;i++){
		addpair(i,i+1);
	}
	while(!pq.empty()){
		item cur=pq.top();
		pq.pop();
		
		if(deleted[cur.l]||deleted[cur.r])continue;
		
		ans.push_back({cur.l,cur.r});
		deleted[cur.l]=true;
		int L=pre[cur.l];
		int R=nxt[cur.r];
		deleted[cur.r]=true;
		nxt[L]=R;
		pre[R]=L;
		if(L>=1&&R<=n)addpair(L,R);
	}
	cout<<ans.size()<<endl;
	for(auto [l,r]:ans){
		cout<<l<<" "<<r<<'\n';
	}
	return 0;
}
