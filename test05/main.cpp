#include <iostream>
 #include <stdio.h>
 #include <windows.h>
 #include <string.h>
 #include <time.h>


int  main()   //������
{
         int n,a,right=0;
         double percent;
         cout<<"Please enter the number of the test:";
         cin>> n >>endl;
         for(int i=0;i<n;i++)
         {
                   a=takeTest();
                   right=right+a;
         }
         cout<<"Powerful!"<<endl;
         cout<<"The number of right:%d"+right<<endl;
         percent=((double)right*100.00)/(double)n;
         cout<<"The percent of right:%0.2f %%\n"+percent<<endl;
}

// �����ȡ���������
char getSignal()
{
    char signal[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    return signal[rand()%4];
}

//��ȡ���������
int random(double start, double end)
{
    return (int)(start+(end-start)*rand()/(RAND_MAX+ 1.0));
}

//��ȡ����������
int getResult(int num1,int num2,char signal)
{
    int res;
    switch(signal)
    {
    case '+':
        res=num1+num2;break;
    case '-':
        res=num1-num2;break;
    case '*':
        res=num1*num2;break;
    case '/':
        res=num1/num2;break;
    default:
        cout<<"���������"<<endl;
    }
    return res;
}

//��Ŀ���ɺ���
int takeTest()
{
    int get;
    int num1,num2,a;
    char signal;

    srand((unsigned)time(NULL));
    signal=getSignal();
    num1=random(0,1000);
    num2=random(1,1000);
if(signal=='-')
    {
        if(num1<num2)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    if(signal=='/')
    {
        if(num2==0)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    cout<<num1+signal+num2<<endl;
    cin>>get<<endl;
    fflush(stdin);   //������뻺����
    if(getResult(num1,num2,signal)==get)
        {
      cout<<"You're right!"<<endl;
        a=1;
        }
    else
    {
        cout<<"It's wrong!\n"<<endl;
        cout<<getResult(num1,num2,signal)<<endl;
        a=0;
    }
    return a;
}
