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
bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();
	bool dp[m + 1][n + 1];
	dp[0][0] = true;
	for (int j = 1; j < n + 1; j++) {
		if (p[j - 1] == '*')
			dp[0][j] = dp[0][j - 2];
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if ((p[j - 1] == s[i - 1]) || (p[j - 1] == '.'))
				dp[i][j] = dp[i - 1][j - 1];
			else if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j-2];
				if ((p[j - 2] == s[i - 1]) || p[j - 2] == '.') {
					dp[i][j] = dp[i][j] | dp[i - 1][j];
				}
			}
			else {
				dp[i][j] = false;
			}
		}
	}
	return dp[m][n];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	string p;
	cin >> p;
	cout << isMatch(s, p);
}