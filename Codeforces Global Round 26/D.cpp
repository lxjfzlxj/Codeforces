# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N];
int ra[N],f[N];
void _() {
	scanf("%s",s+1);
	int n,i,st,mid,r;
	long long ans=0;
	n=strlen(s+1);
	for(i=1;i<=n && s[i]=='a';i++);
	if(i>n) report("%d\n",n-1);
	st=i; mid=r=st;
	for(i=st+1;i<=n;i++) {
		if(i<=r) f[i]=std::min(f[st+i-mid],r-i+1);
		else f[i]=0;
		while(i+f[i]<=n && s[st+f[i]]==s[i+f[i]]) f[i]++;
		if(i+f[i]-1>r) mid=i, r=i+f[i]-1;
	}
	ra[n+1]=n+1;
	for(i=n;i>=1;i--) {
		if(s[i]=='a') ra[i]=ra[i+1];
		else ra[i]=i;
	}
	for(i=st;i<=n;i++) {
		int j=i+1,len;
		bool ok=true;
		len=i-st+1;
		int las=i,mx1=st-1;
		while(j<=n) {
			if(s[j]=='a') j=ra[j];
			else {
				if(f[j]<len) {
					ok=false;
					break;
				}
				mx1=std::min(mx1,j-las-1);
				las=j+len-1;
				j+=len;
			}
		}
		if(ok) ans+=mx1+1;
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

