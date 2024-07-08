# include <bits/stdc++.h>
# define MOD 777777777
# define N 80000
int w[5][5],a[N],tr[N<<2][4][4];
void pushup(int x,int l,int r,int mid) {
	int i1,i2,i3,i4,i,j;
	for(i=1;i<=3;i++) {
		for(j=1;j<=3;j++) tr[x][i][j]=0;
	}
	for(i2=(a[mid]?a[mid]:1);i2<=(a[mid]?a[mid]:3);i2++) {
		for(i3=(a[mid+1]?a[mid+1]:1);i3<=(a[mid+1]?a[mid+1]:3);i3++) {
			if(!w[i2][i3]) continue;
			for(i1=(a[l]?a[l]:1);i1<=(a[l]?a[l]:3);i1++) {
				for(i4=(a[r]?a[r]:1);i4<=(a[r]?a[r]:3);i4++) {
					tr[x][i1][i4]=(1ll*tr[x<<1][i1][i2]*tr[x<<1|1][i3][i4]+tr[x][i1][i4])%MOD;
				}
			}
		}
	}
}
void fix(int x,int pos) {
	int i;
	for(i=1;i<=3;i++) tr[x][i][i]=(!a[pos] || a[pos]==i?1:0);
}
void build(int x,int l,int r) {
	int mid=l+r>>1;
	if(l==r) {
		fix(x,l);
		return;
	}
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x,l,r,mid);
}
void update(int x,int l,int r,int pos) {
	if(l==r) {
		fix(x,pos);
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(x<<1,l,mid,pos);
	else update(x<<1|1,mid+1,r,pos);
	pushup(x,l,r,mid);
}
int main() {
	int n,m,i,j,v,t,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=3;i++) {
		for(j=1;j<=3;j++) scanf("%d",w[i]+j);
	}
	build(1,1,n);
	while(m--) {
		scanf("%d%d",&v,&t);
		a[v]=t;
		update(1,1,n,v);
		ans=0;
		for(i=1;i<=3;i++) {
			for(j=1;j<=3;j++) ans=(ans+tr[1][i][j])%MOD; 
		}
		printf("%d\n",ans);
	}
	return 0;
}
