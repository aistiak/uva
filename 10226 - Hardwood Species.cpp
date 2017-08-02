
//10226 - Hardwood Species
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    // freopen("out.txt","w",stdout);
    map<string ,int> m ;
    map<string ,int> ::iterator it ;
    int tc , flag = 0;
    double c = 0;
    string s ;
    cin >> tc ;
    getline(cin,s);
    tc = tc + 1; /*test case is one extra because
                  after test case input there is a blank line input which is
                  counted as a test case input so we buffer the test case by
                  one and ignore the first case by setting flag
                 */
    while(tc--) {
        c = 0 ;
        m.clear();

        while(getline(cin,s)) {
            if(s.empty()) {
                break ;
            }
            c++;
            m[s]++;
        }
        if(flag == 1) {
            for(it = m.begin() ; it!=m.end() ; it++) {
                cout << it->first << " " ;
                printf("%.4f\n",(it->second / c)*100 );
            }
            if(tc!=0) {
                cout << endl;
            }
        }
        flag = 1;
    }

    return 0 ;
}
