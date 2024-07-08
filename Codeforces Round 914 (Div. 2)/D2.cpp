# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],b[N],mx[N][20],mn[N][20],lg2[N];
std::set<int> st[N];
int qmax(int l,int r) {
	int k=lg2[r-l+1];
	return std::max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int qmin(int l,int r) {
	int k=lg2[r-l+1];
	return std::min(mn[l][k],mn[r-(1<<k)+1][k]);
}
bool check(int l,int r,int c) {
	return qmax(l,r)<=c && qmin(l,r)>=c;
}
void _() {
	int n,i,j;
	bool b1,b2;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<=n;i++) st[i].clear();
	for(i=1;i<=n;i++) {
		mx[i][0]=a[i];
		mn[i][0]=b[i];
		st[a[i]].insert(i);
	}
	for(i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(j=1;j<=lg2[n];j++) {
		for(i=1;i+(1<<j)-1<=n;i++) {
			mx[i][j]=std::max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
			mn[i][j]=std::min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		}
	}
	for(i=1;i<=n;i++) {
		if(st[b[i]].empty()) report("NO\n");
		b1=b2=false;
		if(i>=*st[b[i]].begin() && check(*--st[b[i]].upper_bound(i),i,b[i])) b1=true;
		if(i<=*--st[b[i]].end() && check(i,*st[b[i]].lower_bound(i),b[i])) b2=true;
		if(!b1 && !b2) report("NO\n");
	}
	puts("YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
