# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int a[N],W,F;
int calc(int x,int y) {
	int ww=(x+W-1)/W,ff=(y+F-1)/F;
	return std::max(ww,ff);
}
std::bitset<1000010> f[2];
void _() {
	int n,i,z,sum=0,ans=2e9;
	scanf("%d%d%d",&W,&F,&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), sum+=a[i];
	f[0].reset(); f[0][0]=1;
	f[1].reset();
	for(i=z=1;i<=n;i++,z^=1) {
		f[z]=f[z^1]|(f[z^1]<<a[i]);
	}
	for(i=0;i<=sum;i++) {
		if(f[z^1][i]) ans=std::min(ans,calc(i,sum-i));
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

