// If A[0] has the smallest endpoint, it can only intersect B[0]. After, we can discard A[0] since it cannot intersect anything else.

// Similarly, if B[0] has the smallest endpoint, it can only intersect A[0], and we can discard B[0] after since it cannot intersect anything else.

// We use two pointers, i and j, to virtually manage "discarding" A[0] or B[0] repeatedly.
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
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<int> result;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		int left = max(A[i][0], B[j][0]);
		int right = min(A[i][1], B[j][1]);
		if (left <= right) {
			result.emplace_back(left, right);
		}
		if (A[i][1] < B[j][1]) {
			++i;
		} else {
			++j;
		}
	}
	return result;
}
// int main() {
// 	fastIO
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n, m;
// 	cin >> n, m;
// 	vector<vector<int>> A(n, vector<int>(m));
// 	vector<vector<int>> B(n, vector<int>(m));
// 	NF(A, n, m);
// 	PNF(A, n, m);
	
// }