# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
struct point{
	int x,c;
};
std::vector<point> vec[N];
int f[N],tr[N<<2],lazy[N<<2];
bool cmp(const point &i,const point &j) {return i.x>j.x;}
void pushdown(int x) {
	if(lazy[x]) {
		lazy[x<<1]+=lazy[x];
		lazy[x<<1|1]+=lazy[x];
		tr[x<<1]+=lazy[x];
		tr[x<<1|1]+=lazy[x];
		lazy[x]=0;
	}
}
void pushup(int x) {
	tr[x]=std::max(tr[x<<1],tr[x<<1|1]);
}
void update(int x,int xl,int xr,int ql,int qr,int v) {
	if(ql<=xl && xr<=qr) {
		tr[x]+=v; lazy[x]+=v;
		return;
	}
	pushdown(x);
	int mid=xl+xr>>1;
	if(ql<=mid) update(x<<1,xl,mid,ql,qr,v);
	if(qr>mid) update(x<<1|1,mid+1,xr,ql,qr,v);
	pushup(x);
}
int query(int x,int xl,int xr,int ql,int qr) {
	if(ql<=xl && xr<=qr) return tr[x];
	pushdown(x);
	int mid=xl+xr>>1,ans=0;
	if(ql<=mid) ans=std::max(ans,query(x<<1,xl,mid,ql,qr));
	if(qr>mid) ans=std::max(ans,query(x<<1|1,mid+1,xr,ql,qr));
	return ans;
}
void _() {
	int n,k,r,i,x,y,c,tot=0,siz;
	scanf("%d%d%d",&n,&k,&r);
	for(i=1;i<=n;i++) {
		scanf("%d%d%d",&x,&y,&c);
		vec[k-y].push_back((point){x,c});
		tot+=c;
	}
	for(i=0;i<k;i++) std::sort(vec[i].begin(),vec[i].end(),cmp);
	f[0]=0;
	for(i=1;i<=k;i++) {
		update(1,0,k-1,0,i-1,-r);
		for(auto p:vec[i]) update(1,0,k-1,0,p.x,p.c);
		f[i]=std::max(f[i-1],query(1,0,k-1,0,i-1));
		update(1,0,k-1,i,i,f[i]);
	}
	printf("%d",tot-f[k]);
}

int main() {
	int T=1;
	// scanf("%d",&T);
	while(T--) _();
	return 0;
}