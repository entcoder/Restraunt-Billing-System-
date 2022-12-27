#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
    int choice;
    int PRICE[20]={20,15,30,30,35,20,15,15,40,50,40,25};
    char MENU[20][100]={"coffee  ","Tea     ","patties ","Cold coffee","Sandwich ","Pohe    ","Samosa  " ,"wadapav ","Idli    ","Ice tea ","Dosa    ","Ice-cream"};
    int i,g,c,j=0,Q=0,e;
    float k=0,Sg=0;
    int m,n,o;
    void Menu();
    void ORDER();


int main()
{   time_t t;
    time(&t);
    cout<<ctime(&t)<<endl;
    Menu();
    ORDER();
    return 0;
}
void Menu()
{   
    cout<<"\t---~~~*****SUNRISE CAFE*****~~~---\t\n";
    cout<<"-----------------------MENU-------------------------\n";
    cout<<"Sr. No.\t\t Item\t\t\tprice\n";
    for(int i=1;i<=12;i++)
    {
        cout<<i<<".\t \t "<<MENU[i-1]<<"\t\t  "<<PRICE[i-1]<<endl;
    }
}
void ORDER()
{
    time_t t;
    time(&t);
struct order
    {
        int n; int p; int q;
    };
    struct order ORDERED[12];
cout<<"________________________________________________\n";
    cout<<"Enter no. of dish to be ordered(0 to STOP) : ";
    cin>>c;
    while(c!=0)
    {
        for(i=1;i<=12;i++)
        {
            if(i==c)
            {
                ORDERED[j].n=c-1;
                ORDERED[j].p=PRICE[c-1];
                cout<<"enter quantity for "<<MENU[c-1]<<": ";
                cin>>ORDERED[j].q;
                j++;
            }


        }
        cout<<"Enter no. of dish to be ordered(0 to STOP) : ";
        cin>>c;

    }
    cout<<"__________________________________________________________________________________\n";
    cout<<"No. \t\tItem\t\t\tprice\t\tQuantity\tAmount\n";
    for(i=0;i<j;i++)
    {
        int m,n,o,p;
        p=ORDERED[i].n,m=ORDERED[i].p,n=ORDERED[i].q,o=m*n;
        cout<<i+1<<"\t\t"<<MENU[p]<<"\t\t"<<m<<"\t\t"<<n<<"\t\t"<<o<<endl;
        k+=o,Q+=n;
    }
    cout<<"__________________________________________________________________________________\n";
    cout<<"Total Qty.= "<<Q<<" \t\t\t\t\t\tsub total= "<<k<<endl;
    cout<<"\t\t\tSGST (2.5%)=\t";
    Sg=0.025*k;
    cout<<Sg<<endl;
    cout<<"\t\t\tCGST (2.5%)=\t";

    cout<<Sg<<endl;
   
    g=1.05*k;
    cout<<"\t\t\tGrand Total(round off) = "<<g;
     cout<<"\n_________________________________________________________________________________\n";
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~THANK YOU!~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"\n__________________________________________________________________________________\n\n\n";
ofstream fout;
    fout.open("bill.txt",ios::app);
    fout<<"SUNRISE CAFE\t\t\t\t\t\t\t\t";
    fout<<ctime(&t);
    fout<<"No. \t\tItem\t\t\tprice\t\t\tQuantity\t\tAmount\n";
    k=Q=0;
    for(i=0;i<j;i++)
    {
        int m,n,o,p;
        p=ORDERED[i].n,m=ORDERED[i].p,n=ORDERED[i].q,o=m*n;
        fout<<i+1<<"\t\t\t"<<MENU[p]<<"\t\t\t"<<m<<"\t\t\t\t"<<n<<"\t\t\t\t"<<o<<endl;
        k+=o,Q+=n;
    }
    fout<<"__________________________________________________________________\n";
    fout<<"Total Qty.= "<<Q<<" \t\t\t\t\tsub total= "<<k<<endl;
    fout<<"\t\t\tSGST (2.5%)=\t";
    fout<<Sg<<endl;
    fout<<"\t\t\tCGST (2.5%)=\t";
    fout<<Sg<<endl;
    fout<<"\t\tGrand Total(round off) = "<<g<<endl;
    fout<<"__________________________________________________________________\n\n\n";
    fout.close();
}
