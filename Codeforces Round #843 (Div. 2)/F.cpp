#include <bits/stdc++.h>
#define report(args...) return printf(args), void()
# define SQ 700 
int u,MOD,f[SQ][SQ],g[SQ],h[SQ];
bool vis[SQ];
int max(int x,int y) {return x>y?x:y;}
int min(int x,int y) {return x<y?x:y;}
void inc(int &x,int y) {(x+=y)>=MOD?x-=MOD:0;}
void _() {
	int n,i,j,k,mn=2e9,l,ans=0,le,ri;
	scanf("%d",&n);
	le=max(sqrt(n)-50,1);
	ri=min(n,sqrt(n)+50);
	for(i=le;i<=ri;i++) mn=min(mn,i+(n+i-1)/i);
	if(u==1) {
		for(k=1;k<=n && k+(n+k-1)/k!=mn;k++);
		printf("%d %d\n",(n+k-1)/k,k);
		for(i=l=1;i<=(n+k-1)/k;i++) {
			for(j=1;j<=k;j++,l++) {
				putchar(l<=n?'#':'.');
			}
			puts("");
		}
	} else {
		for(i=le;i<=ri;i++) {
			if(i+(n+i-1)/i==mn) inc(ans,h[i*((n+i-1)/i)-n]);
		}
		printf("%d %d\n",mn*2,ans);
	}
}

int main() {
	int T=1,i,j,k,c=3;
	scanf("%d%d",&T,&u);
	if(u==2) {
		scanf("%d",&MOD);
		f[0][0]=1;
		for(i=0;i<=650;i++) {
			for(j=0;j<=650;j++) if(f[i][j]) {
				inc(g[i],f[i][j]);
				for(k=j?j:1;i+k<=650;k++) inc(f[i+k][k],f[i][j]);
			}
		}
		for(i=0;i<=650;i++) h[i]=g[i];
		while(c--) {
			for(i=650;i>=0;i--) {
				for(j=650-i;j>=1;j--) inc(h[i+j],1ll*h[i]*g[j]%MOD); 
			}
		}
	}
	while(T--) _();
	return 0;
}

