# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],las[31],pr_n,ls_n,mx[N*40];
struct pair{
	long long x;
	int y;
}pr[N*40],ls[31];
bool cmp(const pair &i,const pair &j) {return i.x<j.x;}
void _() {
	int n,q,i,j,len,val,v;
	scanf("%d%d",&n,&q);
	pr_n=0;
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		pr[++pr_n]=(pair){i,a[i]};
	}
	for(j=0;j<=30;j++) las[j]=2e9;
	for(i=1;i<=n;i++) {
		for(j=0;j<=30;j++) if((a[i]>>j)&1) {
			las[j]=i;
		}
	}
	for(i=1;i<=n;i++) {
		if(i>1) {
			ls_n=0;
			for(j=0;j<=30;j++) if(!((a[i]>>j)&1)) {
				if(las[j]<1e9) {
					len=i-las[j]+1;
					if(las[j]>i) len+=n;
					ls[++ls_n]=(pair){len,j};
				}
			}
			std::sort(ls+1,ls+ls_n+1,cmp);
			val=a[i];
			for(j=1;j<=ls_n;j++) {
				val|=1<<ls[j].y;
				pr[++pr_n]=(pair){1ll*(ls[j].x-1)*(n-1)+i,val};
			}
		}
		for(j=0;j<=30;j++) if((a[i]>>j)&1) {
			las[j]=i;
		}
	}
	std::sort(pr+1,pr+pr_n+1,cmp);
	for(i=1;i<=pr_n;i++) mx[i]=std::max(mx[i-1],pr[i].y);
	while(q--) {
		scanf("%d",&v); v++;
		if(v>mx[pr_n]) puts("-1");
		else printf("%lld\n",pr[std::lower_bound(mx+1,mx+pr_n+1,v)-mx].x);
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

