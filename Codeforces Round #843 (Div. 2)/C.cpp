#include <bits/stdc++.h>
#define report(args...) return printf(args), void()
#define N 110
bool a[N],b[N];
void get(long long x,bool *c) {
	int i;
	for(i=0;i<=62;i++) c[i]=0;
	for(i=62;i>=0;i--) {
		if((x>>i)&1) c[i]=1;
	}
}
void _() {
	long long n,m,ans=0;
	int fg=-1,i;
	scanf("%lld%lld",&n,&m);
	if(n==m) report("%lld\n",n);
	get(n,a); get(m,b);
	for(i=62;i>=0;i--) {
		if(!a[i] && b[i]) report("-1\n");
		else if(a[i] && !b[i]) {
			if(fg==-1) fg=i;
		}
		if(fg!=-1 && b[i]) report("-1\n");
	}
	if(a[fg+1]) report("-1\n"); 
	for(i=fg;i>=0;i--) a[i]=0;
	for(i=fg+1;i<=62 && a[i];i++) a[i]=0;
	a[i]=1;
	for(i=62;i>=0;i--) {
		if(a[i]) ans|=1ll<<i;
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

