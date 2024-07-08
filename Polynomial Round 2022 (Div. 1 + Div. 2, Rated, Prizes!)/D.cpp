# include <bits/stdc++.h>
# define NM 1000010
# define N 100010
int n,m,a[NM],cnt[N],id[N];
int fid(int i,int j) {return (i-1)*m+j;}
int min(int x,int y) {return x<y?x:y;}
bool cmp(const int &i,const int &j) {return cnt[i]<cnt[j];}
void work(int x,int y,int d) {
	int j;
	for(j=1;j<=m && d;j++) {
		if(!a[fid(x,j)] && a[fid(y,j)]) {
			printf("%d %d %d\n",x,y,j);
			a[fid(x,j)]=1; a[fid(y,j)]=0;
			d--;
		}
	}
}
void _() {
	int i,j,c=0,d,k=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) cnt[i]=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			scanf("%d",a+fid(i,j));
			if(a[fid(i,j)]==1) cnt[i]++;
		}
		c+=cnt[i];
	}
	if(c%n) return puts("-1"), void();
	c/=n;
	for(i=1;i<=n;i++) {
		if(cnt[i]>c) k+=cnt[i]-c;
	}
	printf("%d\n",k);
	for(i=1;i<=n;i++) id[i]=i;
	std::sort(id+1,id+n+1,cmp);
	for(i=1,j=n;i<j;) {
		d=min(c-cnt[id[i]],cnt[id[j]]-c);
		work(id[i],id[j],d);
		cnt[id[i]]+=d; cnt[id[j]]-=d;
		while(cnt[id[i]]==c) i++;
		while(cnt[id[j]]==c) j--;
	}
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

