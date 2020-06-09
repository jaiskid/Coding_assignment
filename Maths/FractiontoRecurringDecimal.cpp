// Fraction to Recurring Decimal
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
string fractionToDecimal(int numerator, int denominator) {
	if (!numerator) {
		return "0";
	}
	string ans;
	if (numerator > 0 ^ denominator > 0) {
		ans += '-';
	}
	long n = labs(numerator), d = labs(denominator), r = n % d;
	ans += to_string(n / d);
	if (!r) {
		return ans;
	}
	ans += '.';
	unordered_map<long, int> rs;
	while (r) {
		if (rs.find(r) != rs.end()) {
			ans.insert(rs[r], "(");
			ans += ")";
			break;
		}
		rs[r] = ans.size();
		r *= 10;
		ans += to_string(r / d);
		r %= d;
	}
	return ans;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int numerator;
	cin >> numerator;
	int denominator;
	cin >> denominator;
	cout << fractionToDecimal(numerator, denominator);
}