#include <cstdio>  
#include <stack>  
using namespace std;

int main(){
	int n;
	stack<char> sta;
	scanf("%d%*c", &n);  
    while (n--) {  
        // init  
        while (!sta.empty()) {  
            sta.pop();  
        }  
  
        // enter  
        char ch;  
        while ((ch = getchar()) != '\n') {  
            if (ch == '(' || ch == '[') {  
                sta.push(ch);  
            } 
			else if (ch == ']' || ch == ')')
			{  
                if (sta.empty()) {  
                    sta.push(ch);  
                }   //ÏÝÚå£º Ð¡ÐÄ£©£©£©£©£©£©£©£©£©£©¡¿¡¿¡¿¡¿¡¿¡¿¡¿¡¿À¨ºÅ×é 
  
                if (ch == ']') {  
                    if (sta.top() != '[') {  
                    } else {  
                        sta.pop();  
                    }  
                } else {  
                    if (sta.top() != '(') {  
                    } else {  
                        sta.pop();  
                    }  
                }  
            }  
        }  
  
        if (sta.empty()) {  
            printf("Yes\n");  
        } else {  
            printf("No\n");  
        }  
          
    }  
  
    return 0;  
}
