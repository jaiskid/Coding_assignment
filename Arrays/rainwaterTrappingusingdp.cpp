#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
int trap(vector<int>&height) {
	if (height.size()==0) {
		return 0;
	}
	int n = height.size();
	vector<int>left_max(n), right_max(n);
	left_max[0] = height[0];
	for (int i = 1; i < n; i++) {
		left_max[i] = max(left_max[i - 1], height[i]);
	}
	right_max[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		right_max[i] = max(right_max[i + 1], height[i]);
	}
	int  ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += min(left_max[i], right_max[i]) - height[i];
	}
	return ans;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>height;
	height.resize(n);
	F(height, n);
	cout << trap(height);
}