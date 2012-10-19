#include<stdio.h>
struct bank
{
    int alloc[10];
    int max[10];
    int need[10];
    int c;
}p[10];

int avail[10];
int m,n;
char res[5]={'A','B','C','D','E'};
int safe[20];
int grant[10];
int g=0;


void read()
{
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    int i,j;
    printf("\nEnter the number of resorces:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        p[i].c=0;
        printf("\n\nEnter the details of the process %d:\n",i+1);
        for(j=0;j<m;j++)
        {
            printf("\nEnter the instances of %c allocated:",res[j]);
            scanf("%d",&p[i].alloc[j]);
        }
        for(j=0;j<m;j++)
        {
            printf("\nEnter the instances of %c maximum:",res[j]);
            scanf("%d",&p[i].max[j]);
            p[i].need[j]=p[i].max[j]-p[i].alloc[j];
        }

    }


    printf("\nEnter the total instances of availailable resources:\n");
    for(i=0;i<m;i++)
    {
        printf("%c\t",res[i]);
        scanf("%d",&avail[i]);
    }
}


void display()
{
    int i,j;
    printf(" \t Alloc \t Max \t Need \t avail \n");
    printf(" \t ");
    for(j=0;j<4;j++,printf("\t "))
        for(i=0;i<m;i++)
            printf("%c",res[j]);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t",i);
        for(j=0;j<m;j++)
            printf("%d",p[i].alloc[j]);
        printf("\t");
        for(j=0;j<m;j++)
            printf("%d",p[i].max[j]);
        printf("\t");
        for(j=0;j<m;j++)
            printf("%d",p[i].need[j]);
        printf("\t");
        if(i==0)
        {
            for(j=0;j<m;j++)
                printf("%d\t",avail[j]);
        }
        printf("\n");
    }
}


int over()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(p[i].need[j]!=0)
                return 1;
    return 0;
}
void bankersalgo()
{
    int i,j,k,l;
    for(i=0,l=0;;i++,l++,i=i%n)
    {
        if(over()==0)
        {
            printf("\nAll processes complete\n\nNo Deadlock");
            printf("\n\nSafe state:");
            for(i=0;i<g;i++)
                printf("P%d",safe[i]);
            printf(">");
            break;
        }
        else
        {
            if(p[i].c==0)
            {
                for(j=0;j<m;j++)
                    if(p[i].need[j]>avail[j])
                        break;
                if(j==m)
                {
                    safe[g]=i;
                    g++;
                    p[i].c=1;
                    for(j=0;j<m;j++)
                    {
                        avail[j]=avail[j]-p[i].need[j];
                        p[i].need[j]=0;
                        p[i].alloc[j]=p[i].max[j];
                    }
                    printf("\n\nProcess P%d is executing:\n\n",i);
                    display();
                    for(j=0;j<m;j++)
                    {
                        avail[j]=avail[j]+p[i].alloc[j];
                        p[i].alloc[j]=0;
                        p[i].max[j]=0;
                    }
                    printf("\n\nProcess P%d is completed:\n\n",i);
                    display();
                }
            }
        }
        if(l==25)
        {
            printf("....Deadlock...");
            break;
        }
    }
}

main()
{
    int choice;
    do
    {
        printf("\n\nBANKERS ALGORITHM");
        printf("\n1.Read data\n2.Display data\n3.Safe sequence\n4.Exit\nEnter you choiceoice--");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:read();break;
            case 2:display();break;
            case 3:bankersalgo();break;
            case 4:break;
        }
    }while(choice!=4);
}


