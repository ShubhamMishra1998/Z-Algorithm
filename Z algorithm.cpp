#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void Z(string s1,string s2)
{
	s1 = s2 + "$" + s1;
	vector<ll> v1(100);
	ll r = 0, l = 0, k = 0, n = s1.length();
	for (ll i = 1; i < n; i++)
	{
		if (i > r)
		{
			r = l = i;
			while (r < n&&s1[r - l] == s1[r])
				r++;
			v1[i] = r - l;
			r--;
		}
		else
		{
			k = i - l;
			if (v1[k] < r - i + 1)
				v1[i] = v1[k];
			else
			{
				l = i;
				while (r < n&&s1[r - l] == s1[r])
					r++;
				v1[i] = r;
				r--;
			}
		}
	}
	for (ll i = 0; i < n; i++)
	{
		if (v1[i] == s2.length())
			cout << i - s2.length() - 1 << '\n';
	}
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		Z(s1, s2);
	}
}
