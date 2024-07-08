# include <bits/stdc++.h>
# define N 100010
int fir[N],e_n=1,f[N],dep[N],mxdep[N];
struct edge{
	int nex,to;
}e[N];
void add(int x,int y) {
	e[++e_n]=(edge){fir[x],y};
	fir[x]=e_n;
}
int max(int x,int y) {return x>y?x:y;}
void dfs(int x) {
	int i;
	mxdep[x]=dep[x];
	for(i=fir[x];i;i=e[i].nex) {
		dep[e[i].to]=dep[x]+1;
		dfs(e[i].to);
		mxdep[x]=max(mxdep[x],mxdep[e[i].to]);
		f[x]+=f[e[i].to];
	}
	f[x]=max(f[x],mxdep[x]-dep[x]+1);
}
void _() {
	int n,i,x;
	scanf("%d",&n);
	for(i=2;i<=n;i++) {
		scanf("%d",&x);
		add(x,i);
	}
	dfs(1);
	printf("%d",f[1]);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

