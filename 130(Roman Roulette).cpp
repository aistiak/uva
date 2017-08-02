#include<bits/stdc++.h>
using namespace std ;
int fun(int n , int k)
{

    if(n == 1 || n == 0) {
        return 0 ;
    }

    return ( abs(fun(n-1,k) - k)) % n  ;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int n , k ;
    while(cin >> n >> k , n) {
        cout << fun(n-1,k)+2  << endl;
    }
    return 0 ;
}

