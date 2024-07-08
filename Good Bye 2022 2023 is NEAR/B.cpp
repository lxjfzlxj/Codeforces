# include <bits/stdc++.h>
# define N 200010
int a[N]; 
void _() {
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i+=2) a[i]=n-(i+1)/2+1;
	for(i=2;i<=n;i+=2) a[i]=i/2;
	for(i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

