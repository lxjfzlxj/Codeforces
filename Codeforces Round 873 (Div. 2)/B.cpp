# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int pos[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int abs(int x) {return x>0?x:-x;}
void _() {
	int n,i,x,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		pos[x]=i;
	}
	for(i=1;i<=n;i++) if(i!=pos[i]) {
		if(!ans) ans=abs(pos[i]-i);
		else ans=gcd(ans,abs(pos[i]-i));
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

