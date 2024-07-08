# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],l[N],r[N],sta[N],top;
void _() {
	int n,i,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	top=0; sta[0]=0;
	for(i=1;i<=n;i++) {
		while(top && a[sta[top]]>=a[i]) top--;
		l[i]=sta[top]; sta[++top]=i;
	}
	top=0; sta[0]=n+1;
	for(i=n;i>=1;i--) {
		while(top && a[sta[top]]>=a[i]) top--;
		r[i]=sta[top]; sta[++top]=i;
	}
	for(i=1;i<=n;i++) if(a[i]) {
		cnt++;
		if(l[i]>0 && a[l[i]]==a[i]-1 || r[i]<=n && a[r[i]]==a[i]-1);
		else break;
	}
	puts(i<=n || cnt!=n-1?"NO":"YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

