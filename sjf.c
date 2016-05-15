#include<iostream.h>

#include<conio.h>

void main()

{
    clrscr();

    float at[10],bt[10],p[10],i,j,min,k,l=0,c=0,wt[10],tat[10];

    cout<<"enter the process no.";

    for(i=0; i<6; i++)

        cin>>p[i];

    cout<<"enter the arrival time";

    for(i=0; i<6; i++)

        cin>>at[i];

    cout<<"enter the burst time";

    for(i=0; i<6; i++)

        cin>>bt[i];

    min=at[0];

    for(i=1; i<6; i++)

    {

        if(min>at[i])

        {
            min=at[i];
            l=i;
        }

    }

    int temp=p[l];

    p[l]=p[0];

    p[0]=temp;

    int temp1=at[l];

    at[l]=at[0];

    at[0]=temp1;

    int temp2=bt[l];

    bt[l]=bt[0];

    bt[0]=temp2;

    c=c+bt[0];

    for(i=1; i<6; i++)

    {
        int t=99;

        for(j=i; j<6; j++)

        {

            if(at[j]<=c)
            {
                if(bt[j]<t)
                {
                    t=bt[j];
                    l=j;
                }
                else if(bt[j]==t)
                {
                    if(at[j]<at[l])
                    {
                        t=bt[j];
                        l=j;
                    }
                }
            }

        }


int t1=p[i];

p[i]=p[l];

p[l]=t1;

int t2=at[i];

at[i]=at[l];

at[l]=t2;

int t3=bt[i];

bt[i]=bt[l];

bt[l]=t3;

c=c+bt[i];

}

wt[0]=0;

k=0;

int sum;

for(i=1; i<6; i++)

{
    sum=0;

    for(j=k; j>=0; j--)

        wt[i]=sum-at[i];

    k++;

}

for(i=0; i<6; i++)

{
    tat[i]=wt[i]+bt[i];
}

cout<<"\nprocess\tarrival\tburst\twaiting\ttat";

for(i=0; i<6; i++)

    cout<<"\nP"<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];

cout<<"\nGANTT CHART";

cout<<"\n\t\t______________________________________________________";

cout<<"\n\t";

for(i=0; i<6; i++)

    cout<<"\t"<<"|p"<<p[i];

cout<<"\t|";

cout<<"\n\t\t--------------------------------------------------------";
cout<<"\n\t";
for(i=0; i<6; i++)
    cout<<"\t"<<wt[i]+at[i];
cout<<"\t"<<tat[5]+at[5];
float avgwt=0,avgtat=0;
for(i=0; i<6; i++)
{
    avgwt=avgwt+wt[i];
    avgtat=avgtat+tat[i];
}
cout<<"\n"<<"avgwt="<<avgwt/6<<"\n"<<"avgtat="<<avgtat/6;
getch();
}
