#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<double> ans;

struct punto {
	ll x, y;
	punto(ll x = 0, ll y = 0) : x(x), y(y) {}
	ll m2() {
	return x * x + y * y;
	}
};

punto operator-(punto a, punto b) {
	return punto(a.x - b.x, a.y - b.y);
}

ll cruz(punto a, punto b) {
	return a.x * b.y - a.y * b.x;
}

ll cruz(punto a, punto b, punto c) {
	b = b - a;
	c = c - a;
	return cruz(b, c);
}

ll vuelta_izq(punto a, punto b, punto c) {
	return cruz(a, b, c) > 0;
}

struct comparador_angular {
	punto p;
	comparador_angular(punto p) : p(p) {}

	bool operator()(punto q, punto r) {
		q = q - p;
		r = r - p;
		ll area2 = cruz(q, r);
		if (area2) return area2 > 0;
		return q.m2() < r.m2();
	}
};

struct comparador_lexicografico {
	bool operator()(punto a, punto b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
};

vector<punto> calcula_envolvente(vector<punto> &ps) {
	punto pivote = *min_element(begin(ps), end(ps), comparador_lexicografico());
	sort(begin(ps), end(ps), comparador_angular(pivote));
	vector<punto> envolvente;
	for (punto p : ps) {
		while (envolvente.size() >= 2) {
			int n = envolvente.size();
			punto q = envolvente[n - 1];
			punto r = envolvente[n - 2];
			if (vuelta_izq(r, q, p)) {
				break;
			}
			envolvente.pop_back();
		}
		envolvente.push_back(p);
	}
	return envolvente;
}

double distancia(pair<punto, punto> s, punto p) {
	ll area2 = abs(cruz(s.first, s.second, p));
	double dx = s.first.x - s.second.x;
	double dy = s.first.y - s.second.y;
	double base = hypot(dx, dy);
	return area2 / base;
}

void calcula_ancho(vector<punto> &ps) {
	int n = ps.size();
	double res = numeric_limits<double>::infinity();
	int j = 1;
	for (int i = 0; i < n; ++i) {
		pair<punto, punto> lado = { ps[i], ps[(i + 1) % n] };
		double dist1 = distancia(lado, ps[j]);
		while (true) {
			int k = (j + 1) % n;
			double dist2 = distancia(lado, ps[k]);
			if (dist2 <= dist1) {
				break;
			}
			j = k;
			dist1 = dist2;
		}
		res = min(res, dist1);
		ans.insert(res);
	}
}

int main() {
	int N, R;
	cin >> N >> R;
	vector<punto> ps;
	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		ps.emplace_back(x, y);
	}
	vector<punto> envolvente = calcula_envolvente(ps);
	calcula_ancho(envolvente);
	set<double>::iterator it; 
	for(it = ans.begin(); it != ans.end(); it++) {
		printf("%.10lf\n", *it);
		break;
	}
	return 0;
}