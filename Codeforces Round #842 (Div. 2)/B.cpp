# include <bits/stdc++.h>
# define N 100010
int pos[N];
void _() {
	int n,k,i,x;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		pos[x]=i;
	}
	for(i=1;i<n && pos[i]<pos[i+1];i++);
	printf("%d\n",(n-i+k-1)/k);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

