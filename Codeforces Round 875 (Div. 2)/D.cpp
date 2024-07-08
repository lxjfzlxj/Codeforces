# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
std::vector<int> vec[N];
int a[N],b[N],buc1[N],buc2[N];
void _() {
	int n,i,B,t,j;
	long long ans1=0,ans2=0;
	scanf("%d",&n); B=sqrt(n*2);
	for(i=1;i<=n;i++) vec[i].clear();
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		vec[a[i]].push_back(i);
	}
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<=B;i++) if(!vec[i].empty()) {
		memset(buc1,0,n+5<<2);
		memset(buc2,0,n+5<<2);
		for(j=1;j<=n;j++) {
			t=i*a[j]-b[j];
			if(t>=1 && t<=n) {
				if(a[j]<=B) buc1[t]++;
				else buc2[t]++;
			}
		}
		for(auto x:vec[i]) {
			ans1+=buc1[b[x]];
			ans2+=buc2[b[x]];
			if(a[x]*a[x]==b[x]+b[x]) ans1--;
		}
	}
	printf("%lld\n",ans1/2+ans2);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

