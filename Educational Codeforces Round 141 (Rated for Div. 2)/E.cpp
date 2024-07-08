# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],b[N],c[N];
bool ok[N];
void work(int x) {
	int i;
	for(i=1;i*i<=x;i++) if(!(x%i)) {
		ok[i]=ok[x/i]=false;
	}
}
void _() {
	int n,i,now=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	memset(c,0,n+5<<2);
	for(i=1;i<=n;i++) if(a[i]>b[i]) {
		c[b[i]]++; c[a[i]]--;
	}
	memset(ok,true,n+5);
	for(i=1;i<=n;i++) {
		now+=c[i];
		if(now) work(i);
	}
	for(i=1;i<=n;i++) {
		if(ok[i]) ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++) {
		if(ok[i]) printf("%d ",i);
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

