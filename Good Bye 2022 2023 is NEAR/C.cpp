# include <bits/stdc++.h>
# define N 110
long long a[N];
int cnt[N];
void _() {
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",a+i);
	for(i=1;i<=n;i++) {
		for(j=i+1;j<=n;j++) {
			if(a[i]==a[j]) return puts("NO"), void();
		}
	}
	for(i=2;i<=n/2;i++) {
		for(j=0;j<i;j++) cnt[j]=0;
		for(j=1;j<=n;j++) cnt[a[j]%i]++;
		for(j=0;j<i && cnt[j]>=2;j++);
		if(j==i) return puts("NO"), void();
	}
	puts("YES"); 
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

