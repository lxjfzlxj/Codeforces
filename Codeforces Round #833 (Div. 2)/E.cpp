# include <bits/stdc++.h>
# define N 200010
# define MOD 1000000007
int n,m,a[N],sta[N],f[2222222];
std::vector<int> vec[N];
int id(int x,int y) {return x*(m+1)+y;}
void dfs(int x) {
	int i,j;
	for(i=0;i<=m;i++) f[id(x,i)]=1;
	for(auto v:vec[x]) {
		dfs(v);
		for(j=m;j>=1;j--) f[id(x,j)]=1ll*f[id(x,j-1)]*f[id(v,j)]%MOD;
		f[id(x,0)]=0;
		for(j=1;j<=m;j++) f[id(x,j)]=(f[id(x,j-1)]+f[id(x,j)])%MOD;
	}
	f[id(x,0)]=0;
}
void _() {
	int i,top=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=0;i<=n;i++) vec[i].clear();
	for(i=1;i<=n;i++) {
		while(top && a[sta[top]]<a[i]) top--;
		vec[sta[top]].push_back(i);
		sta[++top]=i;
		
	}
	dfs(0);
	printf("%d\n",f[id(0,m)]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

