# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
bool vis[N];
int b[N];
void _() {
	int n,k,i,x,nex;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	memset(vis,false,n+5);
	for(x=n;k--;x=nex) {
		if(b[x]>n) report("No\n");
		vis[x]=true;
		nex=((x-1-b[x])%n+n)%n+1;
		if(vis[nex]) break;
	}
	puts("Yes");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

