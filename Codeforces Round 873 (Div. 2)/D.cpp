# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
int a[N],l[N],r[N],sta[N],top;
std::vector<int> vec[N];
void _() {
	int n,i;
	long long ans=0,tot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) vec[i].clear();
	sta[top=1]=0;
	for(i=1;i<=n;i++) {
		while(top>1 && a[sta[top]]>a[i]) top--;
		l[i]=sta[top]+1;
		sta[++top]=i;
	}
	for(i=n;i>=1;i--) vec[l[i]].push_back(i);
	sta[top=1]=n+1;
	for(i=n;i>=1;i--) {
		while(top>1 && a[sta[top]]>a[i]) top--;
		r[i]=sta[top]-1;
		sta[++top]=i;
	}
	sta[top=1]=0; 
	for(i=1;i<=n;i++) {
		for(auto j:vec[i]) {
			while(top>1 && a[sta[top]]<a[j]) top--;
			ans+=1ll*(i-sta[top]-1)*(r[j]-j+1);
		}
		while(top>1 && a[sta[top]]<a[i]) top--;
		sta[++top]=i;
	}
	for(i=0;i<n;i++) tot+=1ll*i*(n-i);
	printf("%lld\n",tot-ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

