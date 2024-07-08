# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
int a[N],f[N],n,k;
std::priority_queue<int> q1;
bool check(long long mid) {
	int i;
	long long sum;
	while(!q1.empty()) q1.pop();
	sum=0;
	for(i=1;i<=n;i++) {
		q1.push(a[i]); sum+=a[i];
		while(!q1.empty() && sum>mid) {
			sum-=q1.top();
			q1.pop();
		}
		f[i]=q1.size();
	}
	while(!q1.empty()) q1.pop();
	sum=0;
	for(i=n;i>=1;i--) {
		q1.push(a[i]); sum+=a[i];
		while(!q1.empty() && sum>mid) {
			sum-=q1.top();
			q1.pop();
		}
		if(f[i-1]+q1.size()>=k) return true;
	}
	return false;
}
void _() {
	int i;
	long long l=0,r=0,mid;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		r+=a[i];
	}
	while(l<r) {
		mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

