# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],sta[N],top,ls[N],rs[N];
long long cnt[N];
void solve(int l,int r,int rt,int v) {
	if(!rt) return;
	cnt[r-l+1]+=v-a[rt];
	solve(l,rt-1,ls[rt],a[rt]);
	solve(rt+1,r,rs[rt],a[rt]);
}
void _() {
	int n,i,rt;
	long long m,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	memset(ls,0,n+5<<2);
	memset(rs,0,n+5<<2);
	for(i=1,top=0;i<=n;i++) {
		while(top && a[sta[top]]<=a[i]) ls[i]=sta[top--];
		sta[++top]=i;
	}
	rt=sta[1];
	for(i=n,top=0;i>=1;i--) {
		while(top && a[sta[top]]<a[i]) rs[i]=sta[top--];
		sta[++top]=i;
	}
	memset(cnt,0,n+5<<3);
	solve(1,n,rt,n);
	scanf("%lld",&m);
	for(i=n;i>=1;i--) if(cnt[i]) {
		if(m>=cnt[i]*i) {
			ans+=cnt[i]*(i-1);
			m-=cnt[i]*i;
		} else {
			ans+=1ll*(m/i)*(i-1)+(m%i?m%i-1:0);
			break;
		}
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

