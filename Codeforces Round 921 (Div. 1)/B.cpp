# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
# define int long long
struct harbour{
	int pos,v;
}a[N];
struct arr{
	long long sta,del;
};
typedef std::set<harbour>::iterator iter;
long long tr[N<<2];
arr lazy[N<<2];
std::set<harbour> st;
bool operator <(const harbour &i,const harbour &j) {
	return i.pos<j.pos;
}
void build(int x,int l,int r) {
	if(l==r) {
		iter it=st.lower_bound((harbour){l,0});
		if(it->pos==l) tr[x]=0;
		else {
			iter nex=st.upper_bound((harbour){l,0}),las=nex; las--;
//			printf("%d %d %d %d\n",las->pos,las->v,nex->pos,nex->v);
			tr[x]=1ll*las->v*(nex->pos-l);
//			printf("%d:%lld\n",l,tr[x]);
		}
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	tr[x]=tr[x<<1]+tr[x<<1|1];
}
long long calc(long long sta,long long del,long long len) {
	return sta*len+len*(len-1)/2*del;
}
void pushdown(int x,int xl,int xr,int mid) {
	if(lazy[x].sta || lazy[x].del) {
		tr[x<<1]+=calc(lazy[x].sta,lazy[x].del,mid-xl+1);
		lazy[x<<1].sta+=lazy[x].sta;
		lazy[x<<1].del+=lazy[x].del;
		tr[x<<1|1]+=calc(lazy[x].sta+lazy[x].del*(mid+1-xl),lazy[x].del,xr-mid);
		lazy[x<<1|1].sta+=lazy[x].sta+lazy[x].del*(mid+1-xl);
		lazy[x<<1|1].del+=lazy[x].del;
		lazy[x].sta=lazy[x].del=0; 
	}
}
void update(int x,int xl,int xr,int ql,int qr,arr ar) {
//	printf("(%d,%d) sta:%lld del:%lld\n",ql,qr,ar.sta,ar.del);
	if(ql<=xl && xr<=qr) {
//		printf("pos:%d += %lld\n",xl,calc(ar.sta+ar.del*(xl-ql),ar.del,xr-xl+1));
		tr[x]+=calc(ar.sta+ar.del*(xl-ql),ar.del,xr-xl+1);
		lazy[x].del+=ar.del;
		lazy[x].sta+=ar.sta+ar.del*(xl-ql);
		return;
	}
	int mid=xl+xr>>1;
	pushdown(x,xl,xr,mid);
	if(ql<=mid) update(x<<1,xl,mid,ql,qr,ar);
	if(qr>mid) update(x<<1|1,mid+1,xr,ql,qr,ar);
	tr[x]=tr[x<<1]+tr[x<<1|1];
}
long long query(int x,int xl,int xr,int ql,int qr) {
	if(ql<=xl && xr<=qr) {
		return tr[x];
	}
	int mid=xl+xr>>1;
	pushdown(x,xl,xr,mid);
	long long ans=0;
	if(ql<=mid) ans+=query(x<<1,xl,mid,ql,qr);
	if(qr>mid) ans+=query(x<<1|1,mid+1,xr,ql,qr);
	return ans;
}
void _() {
	int n,m,q,i,op,x,y;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(i=1;i<=m;i++) scanf("%lld",&a[i].pos);
	for(i=1;i<=m;i++) scanf("%lld",&a[i].v), st.insert(a[i]);
	build(1,1,n);
	while(q--) {
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1) {
			iter nex=st.upper_bound((harbour){x,0}),las=nex; las--;
			update(1,1,n,x,x,(arr){-1ll*las->v*(nex->pos-x),0});
			if(las->pos+1<x) update(1,1,n,las->pos+1,x-1,(arr){-1ll*las->v*(nex->pos-x),0});
			if(x+1<nex->pos) update(1,1,n,x+1,nex->pos-1,(arr){1ll*(y-las->v)*(nex->pos-x-1),las->v-y});
			st.insert((harbour){x,y});
		} else {
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
}

signed main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

