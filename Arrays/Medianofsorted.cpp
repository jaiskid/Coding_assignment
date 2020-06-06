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
double FindMedian(vector<int>&A, vector<int>&B) {
	int m = A.size();
	int n = B.size();
	if (m > n) {
		swap(A, B);
		swap(m, n);
	}
	int imin = 0, imax = m, halflen = (m + n + 1) / 2;
	while (imin <= imax) {
		int i = (imin + imax) / 2;
		int j = halflen - i;
		if (i < imax and B[j - 1] > A[i]) {
			imin = i + 1; //i too small
		}
		else if (i > imin and A[i - 1] > B[j])
			imax = i - 1;
		//i too small
		else {
			int maxLeft = 0;
			if (i == 0) {
				maxLeft = B[j - 1];
			}
			else if (j == 0) {
				maxLeft = A[i - 1];
			}
			else {
				maxLeft = max(A[i - 1], B[j - 1]);
			}
			if ((m + n) % 2 == 1) return maxLeft;
			int minRight = 0;
			if (i == m) {
				minRight = B[j];
			}
			else if (j == n) {
				minRight = A[i];
			}
			else {
				minRight = min(A[i], B[j]);
			}
			return (maxLeft + minRight) / 2.0;
		}
	}
	return 0.0;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>A, B;
	A.resize(n);
	B.resize(n);
	F(A, n);
	F(B, n);
	cout << FindMedian(A, B);
}