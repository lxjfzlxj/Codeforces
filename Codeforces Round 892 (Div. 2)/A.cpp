# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int a[N];
void _() {
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	if(a[1]==a[n]) report("-1\n");
	for(i=1;i<n && a[i]==a[i+1];i++);
	printf("%d %d\n",i,n-i);
	for(j=1;j<=i;j++) printf("%d ",a[j]); puts("");
	for(j=i+1;j<=n;j++) printf("%d ",a[j]); puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

