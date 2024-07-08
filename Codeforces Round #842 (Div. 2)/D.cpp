# include <bits/stdc++.h>
# define N 200010
int p[N],vis[N];
void _() {
	int n,i,x,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",p+i);
	memset(vis,0,n+5<<2);
	for(i=1;i<=n;i++) if(!vis[i]) {
		vis[i]=++cnt;
		for(x=p[i];x!=i;x=p[x]) vis[x]=cnt;
	}
	for(i=1;i<n && vis[i]!=vis[i+1];i++);
	printf("%d\n",i<n?n-cnt-1:n-cnt+1);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

