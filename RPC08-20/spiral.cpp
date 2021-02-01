#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		ll n;
		cin >> n;
		n--;

		if (n == 0) {
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}

		ll root = (ll) sqrt(n);

		ll x = 0;
		if (root % 2 != 0) {
			x = -root + (n - root*root);
		} else {
			x = root - (n - root*root);
		}

		ll lim = (root+1)*(root+1) - root*root;
		ll y = -root / 2;
		if (root % 2 != 0) {
			if (n - root*root <= lim/2) {
				y += n - root*root;
			} else {
				y += lim/2;
				y -= n - root*root - lim/2;
			}
		}
		cout << x << ' ' << y << '\n';
	}
}