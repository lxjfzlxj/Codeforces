# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define P 200010
int f[P];
int min(int x,int y) {return x<y?x:y;}
void _() {
	int p,i,j,las;
	scanf("%d",&p);
	memset(f,63,sizeof(f));
	f[0]=0;
	for(i=1;i<=p;i++) {
		for(j=1;j*(j-1)/2<=i;j++) {
			f[i]=min(f[i],f[i-j*(j-1)/2]+j);
		}
	}
	printf("%d %d",f[p],(f[p]*f[p]-2*p-f[p])/2);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

