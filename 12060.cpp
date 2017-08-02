#include<bits/stdc++.h>
#define ll long long
using namespace std ;

ll fun(ll n)
{
    ll c = 0 ;
    while(n>0) {
        n = n /10 ;
        c++;
    }

    return c ;
}
ll gcd(ll m , ll n )
{
    if(m%n == 0) {
        return n ;
    }
    return gcd(n, m % n);
}
int main()
{
    //freopen("out.txt","w",stdout);
    double n , sum , up , down , temp ;
    ll c = 0 ;
    while(cin >> n ,n ) {

        sum = 0 ;
        for(ll i = 0 ; i < (ll) n ; i++) {
            cin >> temp ;
            sum+=temp ;
        }

        up = sum ;
        down = n ;

        ll  result = (ll) floor(up/down);

        if( (double)result == (up/down)) { /// if result is lleger
            cout << "Case " << ++c << ":"<<  endl;
            if (result<0) {
                cout << "- " << result*-1 << endl;
            } else {
                cout << result << endl;
            }
        } else {

            if(abs(down) > abs(up)) {
                cout << "Case " << ++c << ":" << endl;
                if(sum<0) {
                    down*=-1;
                }
                ll g = gcd((ll)up,(ll)down);
                ll dig  = fun((ll) down / g);
                ll space = dig - fun((ll) up/g) ; // flag1
                if(sum<0) {
                    space+=2;
                }
                for (ll k = 0 ; k < space ; k++) {
                    cout << " ";
                }
                cout << (ll) up / g<< endl;
                if(sum < 0) {
                    cout << "- " ;
                }
                for(ll k = 0 ; k<dig ; k++) {
                    cout << "-" ;
                }
                cout << endl;
                space = dig - fun((ll) down/g) ;
                if(sum<0) {
                    space+=2;
                };
                for (ll k = 0 ; k < space ; k++) {
                    cout << " ";
                }

                cout << (ll) down / g << endl;
            } else {
                if(sum>0) {
                    ll rem   =  (ll)up % (ll) down ;
                    ll n_up  =   floor(up/down) ;
                    ll g = gcd((ll) up , (ll) down);
                    cout << "Case " << ++c << ":" << endl;
                    ll dig = fun((ll) down/g);
                    ll space = (dig + fun(n_up)) - fun(rem/g);

                    for( ll k  = 0 ; k <space ; k++) {
                        cout << " ";
                    }

                    cout << rem  / g<< endl;
                    cout << n_up ;
                    for(ll k = 0 ; k<dig ; k++) {
                        cout << "-" ;
                    }
                    cout << endl;
                    space = fun(n_up);
                    //space = (fun((ll)down) + fun(n_up)) - fun(rem);
                    for( ll k  = 0 ; k <space ; k++) {
                        cout << " ";
                    }
                    cout <<(ll) down / g << endl;


                } else { // if sum is minus

                    up*=-1;
                    ll rem   =  (ll)up % (ll) down ;
                    ll n_up  =   floor(up/down) ;
                    ll g = gcd((ll) up , (ll) down);
                    cout << "Case " << ++c << ":" << endl;
                    ll dig = fun((ll) down/g);
                    ll space = (dig + fun(n_up)) - fun(rem/g);
                    space+=2 ; /// for minus sign
//                    cout <<  "fun(n_up) =" << fun(n_up) << endl;
//                    cout << "dig  = " << dig << endl;
//                    cout << "fun(rem) = " << fun(rem/g) << "rem = " << rem /g   << endl;
//                    cout << "space = " << space << endl;
                    for( ll k  = 0 ; k <space ; k++) {
                        cout << " ";
                    }

                    cout << rem  / g<< endl;
                    cout << "- ";
                    cout << n_up ;
                    for(ll k = 0 ; k<dig ; k++) {
                        cout << "-" ;
                    }
                    cout << endl;
                    space = fun(n_up);
                    //space = (fun((ll)down) + fun(n_up)) - fun(rem);
                    space+=2 ; /// for minus
                    for( ll k  = 0 ; k <space ; k++) {
                        cout << " ";
                    }
                    cout <<(ll) down / g << endl;

                }
            }

        }

    }

    return 0 ;
}

