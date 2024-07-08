# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int a[N];
bool in[1111];
void _() {
	int n,i,j,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), a[i]^=a[i-1];
	for(i=1;i<256;i++) in[i]=false;
	in[0]=true;
	for(i=1;i<=n;i++) {
		for(j=0;j<256;j++) if(in[j] && (a[i]^j)>ans) ans=a[i]^j;
		in[a[i]]=true;
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

