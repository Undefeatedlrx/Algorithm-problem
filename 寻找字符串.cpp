#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	int n = 0;
	getline(cin,a);//cin>>遇到空格就结束，getline(cin,string,终止字符），默认为\n
	getline(cin, b);
	int lenb = b.length();
	int lena = a.length();
	for (int i = 0; i <lena; i++)
	{	
		if (!a.compare(i, lenb, b))
			n++;
	}
	cout << n;
	//system("pause");
	return 0;
}
