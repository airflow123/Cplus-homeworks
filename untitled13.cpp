#include<bits/stdc++.h>
using namespace std;
typedef __int128 int128;
void print(int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int128 read(){
	char c;
	c=getchar();
	int f=1;
	int128 x=0;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	int128 a,b,c,d;
	a=read();
	b=read();
	c=read();
	d=read();
	int128 x1,x2,y1,y2,mn,mx;
	x1=a*c;
	x2=a*d;
	y1=b*c;
	y2=b*d;
	mn=min(min(x1,x2),min(y1,y2));
	mx=max(max(x1,x2),max(y1,y2));
	if(mn<-2147483648||mx>2147483647){
		cout<<"long long int"<<endl;
	}else{
		cout<<"int"<<endl;
	}
	return 0;
}
