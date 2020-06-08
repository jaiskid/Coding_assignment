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
void merge(vector<int>&nums1, vector<int>&nums2) {
	int m=nums1.size();
	int n=nums2.size();
	int i = m + n;
	 
	while (m > 0 and n > 0) {
		if (nums1[m - 1] > nums2[n - 1])
		{
			nums1[i - 1] = nums1[m - 1];
			--m;
		}
		else {
			nums1[i - 1] = nums2[n - 1];
			--n;
		}
		--i;
	}
	while (n > 0) {
		nums1[n - 1] = nums2[n - 1];
		n--;

	}
	return;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	cin >> m;
	vector<int>nums1;
	nums1.resize(m);
	F(nums1, m);
	vector<int>nums2;
	int n;
	cin >> n;
	nums2.resize(n);
	F(nums2, n);
	merge(nums1, nums2);
	P(nums1,n+m);

}