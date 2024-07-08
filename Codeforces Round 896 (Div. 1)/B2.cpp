# include <bits/stdc++.h>
# define N 100010
# define report(args...) return printf(args), void()
int a[N],ad[40],dl[40],now[40],t[40],t_n;
void _() {
	int n,i,j,c;
	long long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), sum+=a[i];
	if(sum%n) report("No\n");
	memset(ad,0,sizeof(ad));
	memset(dl,0,sizeof(dl));
	memset(now,0,sizeof(now));
	for(i=1;i<=n;i++) {
		c=a[i]-sum/n;
		t_n=0;
		for(j=0;j<=30;j++) {
			if((abs(c)>>j)&1) t[++t_n]=j;
		}
		if(c==0) continue;
		if(t[t_n]-t[1]!=t_n-1) report("No\n");
		if(c>0) {
			if(t_n>1) now[t[t_n]+1]++, now[t[1]]--;
			else ad[t[1]]++;
		} else {
			if(t_n>1) now[t[t_n]+1]--, now[t[1]]++;
			else dl[t[1]]++;
		}
	}
	for(i=30;i>=0;i--) {
		if(now[i+1]<-ad[i] || now[i+1]>dl[i]) report("No\n");
		if(now[i+1]<0) ad[i]+=now[i+1];
		else dl[i]-=now[i+1];
		now[i]+=now[i+1]; now[i+1]=0;
		now[i]+=ad[i]-dl[i];
	}
	puts(now[0]==0?"Yes":"No");
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
} 
