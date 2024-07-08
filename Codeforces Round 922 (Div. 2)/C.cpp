# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
long long abss(long long x) {
	return x>=0?x:-x;
}
void _() {
	long long a,b,r,x1=0,x2=0;
	scanf("%lld%lld%lld",&a,&b,&r);
	bool fir=true,full=true;
	int i,aa,bb;
	for(i=60;i>=0;i--) {
		int a0=(a>>i)&1,b0=(b>>i)&1,r0=(r>>i)&1,x0;
		if(a0!=b0) {
			if(fir) x0=0, aa=a0, bb=b0;
			else {
				if(full && !r0) x0=0;
				else {
					if(aa) x0=a0;
					else x0=b0;
				}
			}
			fir=false;
		} else {
			x0=0;
		}
		if(x0<r0) full=false;
		if(x0) x1|=1ll<<i;
	}
	fir=true; full=true;
	for(i=60;i>=0;i--) {
		int a0=(a>>i)&1,b0=(b>>i)&1,r0=(r>>i)&1,x0;
		if(a0!=b0) {
			if(fir) x0=(full&&!r0)?0:1, aa=a0, bb=b0;
			else {
				if(full && !r0) x0=0;
				else {
					if(aa) x0=a0;
					else x0=b0;
				}
			}
			fir=false;
		} else {
			x0=0;
		}
		if(x0<r0) full=false;
		if(x0) x2|=1ll<<i;
	}
//	printf("%lld %lld\n",x1,x2);
	printf("%lld\n",std::min(abss((a^x1)-(b^x1)),abss((a^x2)-(b^x2))));
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

