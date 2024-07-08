# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 510
int f[N][N],a[N];
int min(int x,int y) {return x<y?x:y;}
void _() {
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	memset(f,63,sizeof(f));
	f[0][0]=0; a[n+1]=2e9;
	for(i=1;i<=n+1;i++) {
		for(j=0;j<=i;j++) {
			if(a[i-1]<a[i]) f[i][j]=f[i-1][j];
			if(j) {
				for(k=j-1;k<i-1;k++) {
					if(a[k]<a[i]) f[i][j]=min(f[i][j],f[k][j-1]+i-k-1);
				}
				f[i][j]=min(f[i][j],f[i][j-1]);
			}
		}
	}
	for(j=1;j<=n;j++) printf("%d ",f[n+1][j]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

