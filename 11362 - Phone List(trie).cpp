
// 11362 - Phone List
#include<bits/stdc++.h>
using namespace std ;
struct node {
    bool endmark ;
    node *next[10] ;

    // constructor
    node()
    {
        endmark = false ;
        for(int i = 0 ; i<10 ; i++) {
            next[i] = NULL ;
        }
    }

}*root;

void insrt(string str, int len)
{
    node* cur  = root ;

    for(int i = 0 ; i<len ; i++) {
        int id = str[i] - '0' ;
        if(cur->next[id] == NULL) {
            cur->next[id] = new node();

        }
        cur = cur->next[id];
    }
    cur->endmark = true ;
}

bool serch(string str, int len)
{
    node* cur  = root ;

    for(int i = 0 ; i<len ; i++) {
        int id = str[i] - '0' ;
        if(cur->next[id] == NULL) {
            return false ;
            //cur->next[id] = new node();

        }
        cur = cur->next[id];
    }
    return true ;
}
void del(node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i]) {
            del(cur->next[i]);
        }
    delete (cur);
}
bool cmp(string s1 , string s2)
{

    return s1.length() > s2.length() ;
}
int main()
{
   // cout << '1' - '0';

    //freopen("out.txt","w",stdout);

    // char *s[40] ,s1[40];
    string s[10010] ;
    bool conststent ;
    int tc , n;

    cin >> tc ;

    while(tc--) {
//        for(int i = 0 ; i <40 ; i++) {
//            s[i]="";
//        }
        conststent  = true ;
        root = new node();
        cin >> n ;
        for(int i = 0 ; i<n ; i++) {
            s[i] = "";
            cin >> s[i] ;
        }
        sort(s,s+n,cmp);
//        cout << "---------" << endl;
//        for(int i = 0 ; i < n ; i++) {
//            cout << s[i] << endl;
//        }

        // cout << "hlp" <<  endl;
        conststent  = true ;
        for(int i = 0 ; i < n ; i++) {

            if(serch(s[i],s[i].length()) == false) {
               // cout << s[i] << " "<< s[i].length() << endl ;

                  insrt(s[i],s[i].length());


            } else {
                conststent  = false ;
                break;
            }
        }

        if(conststent == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        del(root);

    }

    return 0 ;
}
