# include <bits/stdc++.h>
int lowbit(int x) {return x&(-x);}
void exgcd(int a,int b,int &x,int &y) {
	if(!b) return x=1, y=0, void();
	int tx,ty;
	exgcd(b,a%b,tx,ty);
	x=ty; y=tx-a/b*ty;
}
int inv(int x,int p) {
	int ans,y;
	exgcd(x,p,ans,y);
	return (ans+p)%p;
}
void _() {
	int a,b,d;
	long long mod;
	scanf("%d%d%d",&a,&b,&d);
	if(lowbit(a)<lowbit(d) || lowbit(b)<lowbit(d)) return puts("-1"), void();
	mod=(1ll<<30)*d;
	printf("%lld\n",(-1ll*inv(d,1<<30)*d%mod+mod)%mod);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

