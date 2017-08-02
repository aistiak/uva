// 440 	Eeny Meeny Moo
#include<bits/stdc++.h>
using namespace std ;
int fun(int n , int k)
{

    if(n == 1) {
        return 0 ;
    }

    return (fun(n-1,k)+k)%n ;
}
int main()
{
//   freopen("out.txt","w",stdout);
    int n ;
    while(cin>>n,n) {

        for(int i = 1 ; 1 ; i++) {
            if(fun(n-1,i)+2 == 2) {
                cout << i << endl;
                break ;
            }
        }
    }

    return 0 ;
}

