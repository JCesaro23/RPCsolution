#include <bits/stdc++.h>
using namespace std;
int n1, n2;
int _left, _right;
int rotate_left(){
    if(n1 > n2)
        return (360+n2)-n1;
    return n2 - n1;
}

int rotate_right(){
    if(n1 > n2)
        return n1 - n2;
    return (360-n2)+n1;
}
int main(){
    _left = _right = 0; 
    scanf("%d\n%d", &n1, &n2);
    _left = rotate_left();
    _right = rotate_right();
    if(_left == _right) printf("180\n");
    else if (_left < _right) printf("%d\n", _left);
    else printf("-%d\n",_right);

    return 0;
}