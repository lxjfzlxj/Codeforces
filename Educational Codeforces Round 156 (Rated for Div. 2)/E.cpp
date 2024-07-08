# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
# define M 30
int b[M],pre[M][N],f[1<<20|10],g[1<<20|10];
std::vector<int> ans[M];
struct person{
	int id,val;
}a[N];
void getp(int zt) {
	if(!zt) return;
	int bef=zt^(1<<g[zt]-1),i;
	for(i=f[zt];i<f[bef];i++) ans[g[zt]].push_back(a[i].id);
	getp(bef);
}
void _() {
	int n,m,i,j,k,tot;
	scanf("%d%d",&n,&m); tot=1<<m;
	for(i=1;i<=n;i++) scanf("%d",&a[i].val), a[i].id=i;
	for(i=1;i<=m;i++) scanf("%d",b+i);
	std::sort(a+1,a+n+1,[](const person &i,const person &j){return i.val<j.val;});
	for(i=1;i<=m;i++) {
		for(j=k=n;j>=1;j--) {
			while(k>=1 && 1ll*a[k].val*(j-k+1)<b[i]) k--;
			pre[i][j]=k;
		}
	}
	f[0]=n+1;
	for(i=1;i<tot;i++) {
		for(j=1;j<=m;j++) if((i>>j-1)&1) {
			if(pre[j][f[i^(1<<j-1)]-1]>f[i]) {
				f[i]=pre[j][f[i^(1<<j-1)]-1];
				g[i]=j;
			}
		}
	}
	if(!f[tot-1]) puts("NO");
	else {
		puts("YES");
		getp(tot-1);
		for(i=1;i<=m;i++) {
			printf("%d ",ans[i].size());
			for(auto j:ans[i]) printf("%d ",j);
			puts("");
		}
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

