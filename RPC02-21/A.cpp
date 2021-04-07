/*******************************************************
Name Problem:Retribution!
Problem Category:adhoc
Problem Tester: Julio Cesar Mamani Villena.
Email: mamanivillenajc@gmail.com
*******************************************************/
#include<bits/stdc++.h>
#define PI 2*acos(0.0)
#define MOD 1000000007
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define fast(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

const int MAX = 1000;
const int MAXD = 10000;
const double INF = 10*MAXD*MAXD;

struct point {
    double x, y;
};

point judges[MAX], tar[MAX], feather[MAX];
bool usedJT[MAX], usedJF[MAX], usedT[MAX], usedF[MAX];
int nJudge, nTar, nFeath;

struct element {
    double dist;
    int iJ;
    int iTF;
    bool isTar;
};

int compare(const void* p1, const void* p2)
{
    element* e1 = (element *)p1;
    element* e2 = (element *)p2;
    if (e1->dist < e2->dist)
        return -1;
    else if (e1->dist > e2->dist)
        return 1;
    else if (e1->iJ < e2->iJ)
        return -1;
    else if (e1->iJ > e2->iJ)
        return 1;
    else
        return e1->iTF - e2->iTF;
}

void solve(){
    cin >> nJudge >> nTar >> nFeath;
    element *a = new element[nJudge*nTar + nJudge*nFeath];
    for(int i=0; i<nJudge; i++) {
        cin >> judges[i].x >> judges[i].y;
        usedJT[i] = usedJF[i] = false;
    }
    int nElem = 0;
    for(int i=0; i<nTar; i++) {
        cin >> tar[i].x >> tar[i].y;
        usedT[i] = false;
       for(int j=0; j<nJudge; j++) {
            double xdiff = judges[j].x-tar[i].x;
            double ydiff = judges[j].y-tar[i].y;
            a[nElem].dist = sqrt(xdiff*xdiff + ydiff*ydiff);
            a[nElem].iJ = j;
            a[nElem].iTF = i;
            a[nElem].isTar = true;
            nElem++;
        }
    }
    for(int i=0; i<nFeath; i++) {
        cin >> feather[i].x >> feather[i].y;
        usedF[i] = false;
        for(int j=0; j<nJudge; j++) {
            double xdiff = judges[j].x-feather[i].x;
            double ydiff = judges[j].y-feather[i].y;
            a[nElem].dist = sqrt(xdiff*xdiff + ydiff*ydiff);
            a[nElem].iJ = j;
            a[nElem].iTF = i;
            a[nElem].isTar = false;
            nElem++;
        }
    }
    qsort(a, nElem, sizeof(element), compare);
    double total = 0.0;
    for(int i=0; i<nElem; i++) {
        if (a[i].isTar) {
            if (usedJT[a[i].iJ] || usedT[a[i].iTF])
                continue;
            total += a[i].dist;
            usedJT[a[i].iJ] = true;
            usedT[a[i].iTF] = true;
        }
        else {
            if (usedJF[a[i].iJ] || usedF[a[i].iTF])
                continue;
            total += a[i].dist;
            usedJF[a[i].iJ] = true;
            usedF[a[i].iTF] = true;
        }
    }
    cout << fixed << setprecision(6) << total << endl;
}
int main(){
    solve();
    return 0;
}