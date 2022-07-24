//Problema disponível em: https://codeforces.com/problemset/problem/1530/C
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A[100001],B[100001];
    int t;
    cin>>t;
    while(t--){
        int n, num;
        cin>>n;
        deque<long long> a(n+1,0),b(n+1,0);
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<n;i++)
            cin>>B[i];
        sort(A,A+n);
        sort(B,B+n);
        for(int i=0;i<n;i++){
            a[i+1] = a[i]+A[i];
            b[i+1] = b[i]+B[i];
        }
        int ans = 0;
        int k = n;
        int k_4 = n/4;
        while(a[k]-a[k_4]<b[k]-b[k_4]){
            ans++;
            k++;
            k_4 = k/4;
            a.push_back(a.back()+100);
            b.push_front(0);
        }
        cout<<ans<<endl;

    }
}