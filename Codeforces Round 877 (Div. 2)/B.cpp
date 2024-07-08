# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int d[N];
int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&x), d[x]=i;
	if(d[n]<d[1] && d[n]<d[2]) printf("%d %d\n",d[n],min(d[1],d[2]));
	else if(d[n]>d[1] && d[n]>d[2]) printf("%d %d\n",d[n],max(d[1],d[2]));
	else puts("1 1");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

