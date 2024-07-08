# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,k,i,ans=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++) ans=max(ans,(i+k-1)/k+(n-i+k-1)/k);
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

