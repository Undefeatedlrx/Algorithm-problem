    #include <iostream>  
    using namespace std;  
    int fibo(int n)  
    {  
        if(n==0)  
            return 0;  
        else if(n==1)  
            return 1;  
        else   
            return fibo(n-1)+fibo(n-2);   
    }  
    int main()  
    {  
        int n;  
        cout<<"请输入数列的范围：";  
        cin>>n;  
        cout<<"斐波那契数列前"<<n<<"项如下："<<endl;  
        for(int i=1;i<=n;i++) {  
            cout<<fibo(i)<<"\t";  
        if (i%5==0)  
            cout<<endl;  } 
        return 0;  
    }  
