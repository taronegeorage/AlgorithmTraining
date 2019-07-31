// #include <iostream>

// int result[100];
// using namespace std;
// int main() {
//     int n, m;
//     scanf("%d%d", &n, &m);
    
    

//     for(int i = 0; i < m; i++) {
//         int tmp;
//         scanf("%d", &tmp);
//         result[tmp]++;
//     }
        
//     for(int i = 1; i <= n; i++){
//        cout << result[n] << " ";
//     }
//     int ans = 1000;
//     printf("%d\n", ans);
//     return 0;
// }
#include<iostream>
using namespace std;
 
int a[1005];
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=m;
    while(m--){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i = 1; i <= n; i++){
       cout << a[n] << " ";
    }
    for(int i=1; i<=n; i++)
        if(ans>a[i]) ans=a[i];
    printf("%d\n",ans);
    return 0;
}