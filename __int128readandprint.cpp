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
	int128 a;
	a=read();
	print(a);
	return 0;
}
