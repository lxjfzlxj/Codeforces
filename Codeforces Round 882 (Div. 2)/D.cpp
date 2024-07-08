# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N],t[N];
int n,fa[N],ord[N],ord_n=0,tr[N];
int fin(int x) {return x!=fa[x]?fa[x]=fin(fa[x]):x;}
void add(int x,int y) {
	int i;
	for(i=x;i<=n;i+=i&(-i)) tr[i]+=y;
}
int query(int x) {
	int ans=0,i;
	for(i=x;i>=1;i-=i&(-i)) ans+=tr[i];
	return ans;
}
void _() {
	int m,q,i,l,r,j,x,cnt=0,mk;
	scanf("%d%d%d%s",&n,&m,&q,s+1);
	for(i=1;i<=n+1;i++) fa[i]=i;
	for(i=1;i<=m;i++) {
		scanf("%d%d",&l,&r);
		for(j=fin(l);j<=r;j=fin(j+1)) {
			ord[j]=++ord_n;
			fa[j]=j+1;
		}
	}
	mk=ord_n;
	for(i=1;i<=n;i++) {
		if(fin(i)==i) ord[i]=++ord_n;
	}
//	assert(ord_n==n);
	for(i=1;i<=n;i++) t[ord[i]]=s[i];
	for(i=1;i<=n;i++) {
		if(t[i]=='1') cnt++, add(i,1);
	}
//	for(i=1;i<=n;i++) printf("%d ",ord[i]); puts("");
//	puts(t+1);
	while(q--) {
		scanf("%d",&x);
		x=ord[x];
		if(t[x]=='1') cnt--, add(x,-1), t[x]='0';
		else cnt++, add(x,1), t[x]='1';
		if(cnt<=mk) printf("ans:%d\n",cnt-query(cnt));
		else printf("ans:%d\n",mk-query(mk));
//		printf("%d ans:%d\n",x,cnt-query(cnt));
	} 
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

