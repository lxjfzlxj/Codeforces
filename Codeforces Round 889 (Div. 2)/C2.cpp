# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 30
int n,a[N],ans_n;
struct pair{
	int x,y;
}ans[40];
void solve() {
	int i,mx=-2e9,mxk=0,mn=2e9,mnk=0,cnt=0;
	for(i=1;i<=n;i++) {
		if(a[i]>mx) mx=a[i], mxk=i;
		if(a[i]<mn) mn=a[i], mnk=i;
	}
	ans_n=0;
	if(mx+mn>0) {
		for(i=1;i<=n;i++) {
			if(a[i]<0) cnt++;
		}
		if(cnt<=12) {
			for(i=1;i<=n;i++) {
				if(a[i]<0) ans[++ans_n]=(pair){i,mxk};
			}
			for(i=2;i<=n;i++) ans[++ans_n]=(pair){i,i-1};
		} else {
			while(a[mnk]>-20) a[mnk]*=2, ans[++ans_n]=(pair){mnk,mnk};
			for(i=1;i<=n;i++) {
				if(a[i]>0) ans[++ans_n]=(pair){i,mnk};
			}
			for(i=n-1;i>=1;i--) ans[++ans_n]=(pair){i,i+1};
		}
	} else {
		for(i=1;i<=n;i++) {
			if(a[i]>0) cnt++;
		}
		if(cnt<=12) {
			for(i=1;i<=n;i++) {
				if(a[i]>0) ans[++ans_n]=(pair){i,mnk};
			}
			for(i=n-1;i>=1;i--) ans[++ans_n]=(pair){i,i+1};
		} else {
			while(a[mxk]<20) a[mxk]*=2, ans[++ans_n]=(pair){mxk,mxk};
			for(i=1;i<=n;i++) {
				if(a[i]<0) ans[++ans_n]=(pair){i,mxk};
			}
			for(i=2;i<=n;i++) ans[++ans_n]=(pair){i,i-1};
		}
	}
	printf("%d\n",ans_n);
	for(i=1;i<=ans_n;i++) printf("%d %d\n",ans[i].x,ans[i].y);
}
void _() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	solve();
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

