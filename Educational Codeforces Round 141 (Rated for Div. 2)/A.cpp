# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 55
int a[N];
void _() {
	int n,i,pos;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(pos=n-1;pos>=1 && a[pos]==a[n];pos--);
	if(!pos) report("NO\n");
	puts("YES");
	printf("%d ",a[n]);
	for(i=pos;i>=1;i--) printf("%d ",a[i]);
	for(i=pos+1;i<n;i++) printf("%d ",a[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

