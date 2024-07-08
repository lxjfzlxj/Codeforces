# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],b[N],t[N],t_n;
void _() {
	int n,m,i,mx,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=m;i++) scanf("%d",b+i);
	std::sort(b+1,b+m+1,[](const int &i,const int &j){return i>j;});
	t_n=0; mx=0;
	for(i=n;i>=1;i--) {
		if(a[i]>mx) mx=a[i], t[++t_n]=i;
		else if(a[i]==mx) t[t_n]=i;
	}
	t[t_n+1]=1;
	for(i=t_n,j=1;i>=1;i--) {
		for(k=t[i+1];k<t[i];k++) printf("%d ",a[k]);
		while(j<=m && b[j]>=a[t[i]]) printf("%d ",b[j]), j++;
	}
	for(k=t[1];k<=n;k++) printf("%d ",a[k]);
	while(j<=m) printf("%d ",b[j]), j++;
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

