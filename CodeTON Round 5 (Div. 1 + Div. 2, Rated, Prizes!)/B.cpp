# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int n,x,a[N],b[N],c[N];
int work(int *a) {
	int i,ans=0;
	for(i=1;i<=n && (ans|a[i]|x)==x;ans|=a[i],i++);
	return ans;
}
void _() {
	int i;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<=n;i++) scanf("%d",c+i);
	puts((work(a)|work(b)|work(c))==x?"Yes":"No");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}