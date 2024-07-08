# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 500010
int a[N],b[N];
long long c[N],sumb[N<<2],nd[N<<2],ans[N<<2],of[N<<2];
void single(int x,int id) {
	sumb[x]=b[id];
	nd[x]=std::max(b[id]-a[id],0);
	of[x]=std::max(a[id]-b[id],0);
	ans[x]=std::min(a[id],b[id]);
}
void pushup(int x) {
	sumb[x]=sumb[x<<1]+sumb[x<<1|1];
	nd[x]=nd[x<<1]+std::max(nd[x<<1|1]-of[x<<1],0ll);
	of[x]=std::max(of[x<<1]-nd[x<<1|1],0ll)+of[x<<1|1];
	ans[x]=ans[x<<1]+ans[x<<1|1]+std:q:min(of[x<<1],nd[x<<1|1]); 
}
void build(int x,int l,int r) {
	if(l==r) {
		single(x,l);
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
void update(int x,int xl,int xr,int pos) {
	if(xl==xr) {
		single(x,xl);
		return;
	}
	int mid=xl+xr>>1;
	if(pos<=mid) update(x<<1,xl,mid,pos);
	else update(x<<1|1,mid+1,xr,pos);
	pushup(x);
}
void _() {
	int n,q,i,p;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<n;i++) scanf("%lld",c+i);
	build(1,1,n);
	while(q--) {
		scanf("%d",&p);
		scanf("%d%d%lld",a+p,b+p,c+p);
		update(1,1,n,p);
		printf("%lld\n",ans[1]);
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}
