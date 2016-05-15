
#include<iostream>
using namespace std;
int main()
{
    int p[6],a[6],b[6],rt[6],wt[6],tat[6],i,j,k,n,c,sum=0,x=0,f=0;
    float avgw=0,avgt=0;
    cout<<"enter the no. of processes";
    cin>>n;
    cout<<"PROCESS";
    for(i=0; i<n; i++)
        cin>>p[i];
    cout<<"ARRIVAL TIME";
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"BURST TIME";
    for(i=0; i<n; i++)
        cin>>b[i];
    for(i=0; i<n; i++)
        rt[i]=b[i];
    for(i=0; i<n; i++)
        sum+=b[i];
    for(i=0; i<n; i++)
        wt[i]=0;
    int d[sum];
    for(c=0; c<sum; c++)
    {
        int min=50;
        for(i=0; i<n; i++)
        {
            if(a[i]<=c && rt[i]>0)
            {
                if(rt[i]<min)
                {
                    min= rt[i];
                    k=i;

                }
            }
        }
        d[x++] =k;
        rt[k]=rt[k]-1;
        for(j=0; j<n; j++)
        {
            if(rt[j]>0 && a[j]<=c && j!=k)
            {
                wt[j]+=1;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        avgw+=wt[i];
    }
    for(i=0; i<n; i++)
    {
        tat[i]=wt[i]+b[i];
        avgt+=tat[i];
    }
    cout<<"\n\nGANTT CHART: \n\n";
    cout<<"process arrival time burst time waiting time turnaround time \n";
    for(i=0; i<n; i++)
        cout<<"p"<<p[i]<<"\t \t"<<a[i]<<"\t \t"<<b[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
    cout<<"\nAvg waiting time="<<avgw/n;
    cout<<"\nAvg turnaround time="<<avgt/n;
    cout<<"\n_________________________________________________________________\n";
    for(i=0; i<x; i++)
    {
        cout<<"|"<<"p"<<d[i]<<" ";
    }
    cout<<"|\n_________________________________________________________________\n";
    for(i=0; i<=sum; i++)
    {
        if(i<=9)
            cout<<i<<" ";
        else
            cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}
