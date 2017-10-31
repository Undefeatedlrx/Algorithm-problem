#include<iostream>  
#include<string>  
#include<stdio.h>  
#include<cmath>  
using namespace std;  
  
int main () {  
    int t;  
    int count;  
    int flag[8];  
    char dep[8];  
    char leaf[256];  
    char ans[256];  
    int res = 0;  
    int cas = 0;  
    while (scanf("%d",&t) && t) {  
        getchar();  
        for (int i = 0; i < t ;i++) {  
            getchar();  
            scanf("%d",&flag[i]);  
            getchar();  
        }  
        for (int i = 0 ; i < pow(2,t) ;i++) {  
            scanf("%c",&leaf[i]);  
        }  
        scanf("%d",&count);  
        getchar();  
        for (int i = 0; i < count ;i++) {  
            for (int j = 0; j < t ;j++) {  
                scanf ("%c",&dep[j]);  
            }  
            getchar();  
            for (int k = t - 1,l = 0 ; k >= 0;k--,l++ ) {  
                res += (dep[flag[l] - 1] - 48) * pow (2,k);  
            }  
            ans[i] = leaf[res];   
            ans[i + 1] = '\0';  
            res = 0;  
  
        }  
        printf("S-Tree #%d:\n%s\n\n",++cas,ans);  
    }  
    return 0;  
}  
