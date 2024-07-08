# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 260
int sta[N],top=0;
void _() {
	int n,i,j,k,ans=0,sum,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			sum=0; now=1; top=0;
			for(k=n;k>=1;k--) if(k!=i) {
				for(;now<=i*j/k && now<=n;now++) {
					if(now!=j) sta[++top]=now;
				}
				if(!top) break;
				sum+=k*sta[top]; top--;
			}
			ans=std::max(ans,sum);
		}
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

