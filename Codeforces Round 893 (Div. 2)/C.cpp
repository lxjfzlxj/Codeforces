# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
bool vis[N];
int ans[N],ans_n;
void _() {
	int n,i,j;
	scanf("%d",&n);
	memset(vis,false,n+5);
	ans_n=0;
	for(i=2;i<=n;i++) if(!vis[i]) {
		for(j=i;j<=n;j*=2) ans[++ans_n]=j, vis[j]=true;
	}
	for(i=1;i<=n;i++) {
		if(!vis[i]) ans[++ans_n]=i;
	}
	for(i=1;i<=ans_n;i++) printf("%d ",ans[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

