# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
# define MOD 998244353
int n,a[N],sta[N],top,l[N],r[N],f[N];
struct BIT{
	int tr[N];
	void init() {
		memset(tr,0,n+5<<2);
	}
	void add(int x,int y) {
		int i;
		for(i=x;i<=n+2;i+=i&(-i)) tr[i]=(tr[i]+y)%MOD;
	}
	int query(int x) {
		int i,ans=0;
		for(i=x;i>=1;i-=i&(-i)) ans=(ans+tr[i])%MOD;
		return ans;
	}
}T1,T2;
void _() {
	int i,sum;
	scanf("%d",&n);
	for(i=2;i<=n+1;i++) scanf("%d",a+i);
	a[1]=a[n+2]=2e9;
	for(i=2,top=0;i<=n+1;i++) {
		while(top && a[sta[top]]>a[i]) top--;
		l[i]=top?sta[top]+1:1; sta[++top]=i;
	}
	for(i=n+1,top=0;i>=2;i--) {
		while(top && a[sta[top]]>a[i]) top--;
		r[i]=top?sta[top]-1:n+2; sta[++top]=i;
	}
	l[1]=r[1]=1; l[n+2]=r[n+2]=n+2;
	T1.init(); T2.init();
	f[1]=sum=1; T1.add(1,1); T2.add(r[1],1);
	for(i=2;i<=n+2;i++) {
		f[i]=((2ll*sum-T1.query(l[i]-1)-T2.query(i-1))%MOD+MOD)%MOD;
		T1.add(i,f[i]); T2.add(r[i],f[i]);
		sum=(sum+f[i])%MOD;
	}
	printf("%d\n",f[n+2]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

