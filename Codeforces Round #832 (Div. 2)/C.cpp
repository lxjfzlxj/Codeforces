# include <bits/stdc++.h>
# define N 100010
int a[N];
void _() {
	int n,i,mn=2e9;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(i>=2 && a[i]<mn) mn=a[i];
	}
	puts(a[1]-1>=mn?"Alice":"Bob");
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

