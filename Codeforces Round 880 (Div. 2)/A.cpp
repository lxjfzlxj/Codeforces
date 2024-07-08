# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int buc[N];
void _() {
	int n,i,x;
	scanf("%d",&n);
	memset(buc,0,sizeof(buc));
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		buc[x]++;
	}
	for(i=0;i<99 && buc[i]>=buc[i+1];i++);
	puts(i<99?"NO":"YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

