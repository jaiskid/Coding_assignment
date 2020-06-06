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
vector<vector<int>>threeSum(vector<int>&nums) {
	vector<vector<int>>res;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++) {
		int target = -nums[i];
		int front = i + 1;
		int back = nums.size() - 1;
		while (front < back) {
			int sum = nums[front] + nums[back];
			//finding answer which start from number nums[i]
			if (sum < target) {
				front++;
			}
			else if (sum > target) {
				back--;
			}
			else {
				vector<int>triplet(3, 0);
				triplet[0] = nums[i];
				triplet[1] = nums[front];
				triplet[2] = nums[back];
				res.push_back(triplet);
				//processing duplicates of numbers 2
				while (front < back and nums[front] == triplet[1]) front++;
				while (front < back and nums[back] == triplet[2]) back--;

			}
		}
		while (i + 1 < nums.size() and nums[i + 1] == nums[i])
			i++;
	}
	return res;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	F(nums, n);
	vector<vector<int>>sum = threeSum(nums);
	PNF(sum,sum.size(),sum[0].size());
}