#include<stdio.h>

void main()

{

    Int

    p[5],max[5][3],alloc[5][3],need[5][3],flag[5],i,j,n=3,avail[5][3],c1=1,c2=0,av=0,seq[5],an[3],af,ar;

    char ch[3]="ABC";

    printf("no. of processes is 3\nno of resources is 3\n");

    for(i=0; i<n; i++)

    {

        printf("\nprocess %d:\nEnter allocuted resources\n",i+1);

        p[i]=i+1;

        flag[i]=0;

        for(j=0; j<3; j++)

        {

            printf("%c : ",ch[j]);

            scanf("%d",&alloc[i][j]);

        }

        printf("\nMaximum allotment:\n");

        for(j=0; j<3; j++)

        {

            printf("%c : ",ch[j]);

            scanf("%d",&max[i][j]);

            need[i][j]=max[i][j]-alloc[i][j];

        }

    }

    printf("Enter the resources available of A B & C");

    scanf("%d%d%d",&avail[0][0],&avail[0][1],&avail[0][2]);

//Request handling

    af=1;

    printf("Resource requesting process (1-5): ");

    scanf("%d",&ar);

    ar--;

    printf("Enter additional need:\n");

    for(i=0; i<3; i++)

    {

        scanf("%d",an[i]);

        if((an[i]>need[ar][i])||(an[i]>avail[0][i]))

            af=0;
    }

    if(af==0)

        printf("Request cant be handled\n & if we continue normally, we get:\n");

    else

    {

        for(i=0; i<3; i++)

        {

            need[ar][i]=-an[i];

            avail[0][i]=-an[i];

        }

    }

//Execution

    while(c2<n)

    {

        if(c1==0)

            break;

        c1=0;

        for(i=0; i<n; i++)

        {

            if(flag[i]==0)

            {

                if((need[i][0]<=avail[av][0])&&(need[i][1]<=avail[av][1])&&(need[i][2]<=avail[av][2]))

                {

                    flag[i]=1;

                    av++;

                    seq[c2]=i+1;

                    for(j=0; j<3; j++)

                        avail[av][j]=avail[av-1][j]+alloc[i][j];

                    c1++;

                    c2++;

                }

            }

        }

    }

    printf("\nProcess table:\nPro.\t Alloc \t MAX \t\t NEED \tAvailable\n \tA B C \tA B C

           \tA B C \tA B C\n");

    for(i=0; i<n; i++)

    {

        printf("\n P%d \t",i+1);



        for(j=0; j<3; j++)

        {

            printf("%d ",alloc[i][j]);

        }

        printf("\t");

        for(j=0; j<3; j++)

        {

            printf("%d ",max[i][j]);

        }

        printf(" \t");
        for(j=0; j<3; j++)

        {

            printf("%d ",need[i][j]);

        }

        printf(" \t");

        for(j=0; j<3; j++)

        {

            printf("%d ",avail[i][j]);

        }

    }

    printf("\n\n");

    if(c2<5)

        printf("Deadlock");

    else

    {

        printf("\nsafe sequence\n");

        for(i=0; i<5; i++)

            printf(" P%d",seq[i]);

    }

}
