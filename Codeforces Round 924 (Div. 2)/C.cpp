# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
int ans[11111],ans_n,t1[11111],t2[11111];
void work(int n,int *a) {
	if(n<0) return;
//	printf("work %d\n",n);
	int i;
	for(i=1;i*i<=n;i++) {
		if(n%i==0) a[++a[0]]=i, i!=n/i?a[++a[0]]=n/i:0;
	}
}
void _() {
	int x,n,i;
	scanf("%d%d",&n,&x);
	ans_n=0;
	t1[0]=t2[0]=0;
	work(n-x,t1);
	work(n+x-2,t2);
	for(i=1;i<=t1[0];i++) {
		if(t1[i]%2==0 && (t1[i]+2)/2>=x) ans[++ans_n]=(t1[i]+2)/2; 
	}
	for(i=1;i<=t2[0];i++) {
		if(t2[i]%2==0 &&(t2[i]+2)/2>=x) ans[++ans_n]=t2[i]/2+1;
	}
	std::sort(ans+1,ans+ans_n+1);
	ans_n=std::unique(ans+1,ans+ans_n+1)-ans-1;
	printf("%d\n",ans_n);
//	for(i=1;i<=ans_n;i++) printf("%d ",ans[i]);
//	puts("");
//	for(i=1;i<=ans_n;i++) {
//		if((n-1)%(2*ans[i]-2)+1==x || (n-1)%(2*ans[i]-2)+1==2*ans[i]-x);
//		else printf("error %d\n",ans[i]);
//	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

