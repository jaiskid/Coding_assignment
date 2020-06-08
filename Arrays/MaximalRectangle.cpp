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

int largestRectangleArea(vector<int>&height) {
	stack<int>increasing_height;
	int maxArea = 0;
	for (int i = 0; i <= height.size();) {
		if (increasing_height.empty() or (i < height.size() and height[increasing_height.top()] < height[i])) {
			increasing_height.emplace(i);
			i++;
		}
		else {
			auto h = height[increasing_height.top()];
			increasing_height.pop();
			auto left = increasing_height.empty() ? -1 : increasing_height.top();
			maxArea = max(maxArea, h * (i - left - 1));
		}
	}
	return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
	int res = 0;
	if (matrix.empty() || matrix[0].empty())
		return 0;
	vector<int> height(matrix[0].size(), 0);
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
		}
		res = max(res, largestRectangleArea(height));
	}
	P(height, height.size());
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
	int m;
	cin >> m;
	vector<vector<char> > matrix( n , vector<char> (m, 0));
	NF(matrix, n, m);
	// PNF(matrix, n, m);
	cout << maximalRectangle(matrix);
}