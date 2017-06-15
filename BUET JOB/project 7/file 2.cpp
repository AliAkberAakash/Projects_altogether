#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;



int main()
{
    int n,amount;
    int a[1000];
    int c;
    map <int,int> res;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    scanf("%d", &amount);

    sort(a,a+n);
    c=0;

    while(amount>0)
    {
        for(int i=n-1; i>=0; i--)
            if(a[i]<=amount)
            {
                res[a[i]]++;
                amount-=a[i];
                c++;
                break;
            }
    }


     cout<< c <<endl;

     map <int, int> :: reverse_iterator it;

     for(it=res.rbegin(); it!=res.rend();  it++)
        cout<< it->first <<" "<< it->second <<endl;


    return 0;
}
