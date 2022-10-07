#include<stdio.h>
#include<string.h>
void start();
void addmovie();
void adm();
void option();
int username();
void signup();
void admin();
int password();
void signin();
void show();
void bookticket();
void viewtransaction();
void editshow();
void seats();
void remf();
void tickets(int x);
struct order{
    char m[20];
    char p[20];
}o1;
struct seat{
    int a;
};
struct show{
    char movie[20];
};
struct movie{
    char m[50];
};
int main()
{
    start();
    return 0;
}
void start()
{
    printf("\t\t\t\t-----WELCOME TO MOVIE BOOKING-----");
    printf("\n\t\t\t 1. sign up");
    printf("\n\t\t\t 2.sign in");
    printf("\n\t\t\t 3.admin");
    printf("\n\t\t\t4.exit");
    option();
}
void option(){
    printf("\nEnter your choice");
    int c;
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        signup();
        break;
        case 2:
        signin();
        break;
        case 3:
        admin();
        break;
        case 4:
        printf("thank you");
        break;
    }
}
void signup()
{
    char u[100],pw[100];
    printf("\nEnter your username:");
    scanf("%s",u);
    int s=0;
    FILE *fp2;
    fp2=fopen("accounts.txt","r");
    struct order o3;
    while(fread(&o3,sizeof(struct order),1,fp2))
    {
        if(strcmp(o3.m,u)==0){
            printf("\nEnter your password:");
            scanf("%s",pw);
            s=1;
            if(strcmp(o3.p,pw)==0){
                show();
            }
            else{
                printf("password wrong");
            }
        }
    }
    if(s==0){
        printf("\ninvalid username");
    }
}
void signin(){
    FILE *fp;
    fp=fopen("accounts.txt","a");
    int r=username(),r1;
    if(r==0)
    {
        r1=password();
        if(r1==0){
            printf("\nAccount is created");
            fwrite(&o1,sizeof(struct order),1,fp);
            FILE *fp2;
            char t[]=".txt";
            char n[strlen(o1.m)+strlen(t)];
            sprintf(n,"%s%s",o1.m,t);
            fp2=fopen(n,"w");
            fclose(fp2);
            signup();
        }
    }
    else{
        printf("\nERROR");
    }
    fclose(fp);
}
int username()
{
    printf("\nEnter the username(space not allowed):");
    scanf("%s",o1.m);
    int s=0;
    char m[strlen(o1.m)];
    FILE *fp1;
    fp1=fopen("accounts.txt","r");
    struct order o2;
    while(fread(&o2,sizeof(struct order),1,fp1)){
        if(strcmp(o1.m,o2.m)==0){
            s++;
        }
    }
    if(s==0){
        printf("\nConfirm the username:");
        scanf("%s",&m);
        if (strcmp(o1.m,m)==0)
        {
            return 0;
        }
        else{
            printf("\nnot match");
            username();
        }
    }
    else{
        printf("\nusername is already taken enter another username");
        username();
    }
}
int password()
{
    printf("\nEnter the password:");
    scanf("%s",o1.p);
    char p[strlen(o1.p)];
    
    printf("\nConfirm your password:");
    scanf("%s",&p);
    if(strcmp(o1.p,p)==0)
    {
        return 0;           
    }
    else{
        printf("\nNot match");
        password();
    }
}
void admin(){
    printf("\nEnter admin id:");
    char a[]="m__mathan";
    char pwd[]="mathan9567";
    char a1[strlen(a)];
    char pwd1[strlen(pwd)];
    scanf("%s",a1);
    printf("\nEnter password:");
    scanf("%s",pwd1);
    if(strcmp(a,a1)==0)
    {
        if(strcmp(pwd,pwd1)==0){
            adm();
        }
    }
}
void adm()
{
    printf("\n1.new movie");
    printf("\n2.edit show");
    int f;
    scanf("%d",&f);
    switch(f)
    {
        case 1:
        addmovie();
        break;
        case 2:
        editshow();
        break;
    }
}
void addmovie()
{
    FILE *fp4;
    fp4=fopen("admin.txt","w");
    struct movie m1;
    printf("\nEnter the movie name:");
    scanf("%s",m1.m);
    fwrite(&m1,sizeof(struct movie),1,fp4);
    fclose(fp4);
    printf("\nmovie is added");
    remf();
}
void remf()
{
    remove("firstshow.txt");
    remove("secondshow.txt");
    remove("thirdshow.txt");
    remove("fourthshow.txt");
    remove("fifthshow.txt");
}
void show()
{
    printf("\n\t\t\t 1.book ticket");
    int ch;
    printf("\nenter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        bookticket();
        break;
    }
}
void bookticket()
{
    FILE *fp6;
    fp6=fopen("admin.txt","r");
    struct movie m2;
    while(fread(&m2,sizeof(struct order),1,fp6))
    {
        printf("\nMovie name:%s",m2.m);
    }
    fclose(fp6);
    FILE *fp7;
    fp7=fopen("show.txt","r");
    printf("\nShowtimings:");
    struct show f1;
    while(fread(&f1,sizeof(struct show),1,fp7))
    {
        printf("\t%s",f1.movie);
    }
    fclose(fp7);
    seats();
}
void editshow(){
    FILE *fp8;
    fp8=fopen("show.txt","w");
    printf("\n1.special show");
    printf("\n2.normalshow");
    printf("\n3.repeat show");
    int g;
    scanf("%d",&g);
    if(g==1){
    struct show f,s,th,fo,fiv;
    printf("\ntiming of first show:");
    scanf("%s",f.movie);
    printf("\ntiming of second show:");
    scanf("%s",s.movie);
    printf("\ntiming of third show:");
    scanf("%s",th.movie);
    printf("\ntiming of four show:");
    scanf("%s",fo.movie);
    printf("\ntiming of five show:");
    scanf("%s",fiv.movie);
    fwrite(&f,sizeof(struct show),1,fp8);
    fwrite(&s,sizeof(struct show),1,fp8);
    fwrite(&th,sizeof(struct show),1,fp8);
    fwrite(&fo,sizeof(struct show),1,fp8);
    fwrite(&fiv,sizeof(struct show),1,fp8);
    if(fwrite != 0)
      printf("Contents to file written successfully !\n");
    else
      printf("Error writing file !\n");
    remf();
    }
    else if(g==2){
    struct show f,s,th,fo;
    printf("\ntiming of first show:");
    scanf("%s",f.movie);
    printf("\ntiming of second show:");
    scanf("%s",s.movie);
    printf("\ntiming of third show:");
    scanf("%s",th.movie);
    printf("\ntiming of four show:");
    scanf("%s",fo.movie);
    fwrite(&f,sizeof(struct show),1,fp8);
    fwrite(&s,sizeof(struct show),1,fp8);
    fwrite(&th,sizeof(struct show),1,fp8);
    fwrite(&fo,sizeof(struct show),1,fp8);
    if(fwrite != 0)
      printf("Contents to file written successfully !\n");
    else
      printf("Error writing file !\n");
    remf();
    }
    else if(g==3)
    {
        remf();
    }
    fclose(fp8);
}
void seats()
{
    printf("\nenter your  time of show:");
    int t, i=0;
    scanf("%d",&t);
    if(t==1)
    {
        FILE *f9;
        int s=1;
        f9=fopen("firstshow.txt","r");
        struct seat se;
        int a[9][16];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                a[i][j]=s;
                s++;
            }
        }
        int n=0;
        while(fread(&se,sizeof(struct seat),1,f9))
        {
            n++;
        }
        fclose(f9);
        FILE *f12;
        f12=fopen("firstshow.txt","r");
        int st[n];
        int c=0;
        struct seat f;
        while(fread(&f,sizeof(struct seat),1,f12))
        {
            st[c]=f.a;
            c++;
        }
        fclose(f12);
        int y=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int m=0;m<n;m++)
                {
                    if(st[m]==a[i][j])
                    {
                        y=1;
                        break;
                    }
                    else{
                        y=0;
                    }
                }
                if(y==0)
                {
                    printf("%d\t",a[i][j]);
                }
                else
                {
                    printf("B\t");
                }
            }
            printf("\n");
        }
        fclose(f9);
        tickets(1);
    }
    else if (t==2)
    {
        FILE *f9;
        int s=1;
        f9=fopen("secondshow.txt","r");
        struct seat se;
        int a[9][16];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                a[i][j]=s;
                s++;
            }
        }
        int n=0;
        while(fread(&se,sizeof(struct seat),1,f9))
        {
            n++;
        }
        fclose(f9);
        FILE *f12;
        f12=fopen("secondshow.txt","r");
        int st[n];
        int c=0;
        struct seat f;
        while(fread(&f,sizeof(struct seat),1,f12))
        {
            st[c]=f.a;
            c++;
        }
        fclose(f12);
        int y=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int m=0;m<n;m++)
                {
                    if(st[m]==a[i][j])
                    {
                        y=1;
                        break;
                    }
                    else{
                        y=0;
                    }
                }
                if(y==0)
                {
                    printf("%d\t",a[i][j]);
                }
                else
                {
                    printf("B\t");
                }
            }
            printf("\n");
        }
        fclose(f9);
        tickets(2);
    }
    else if(t==3)
    {
        FILE *f9;
        int s=1;
        f9=fopen("thirdshow.txt","r");
        struct seat se;
        int a[9][16];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                a[i][j]=s;
                s++;
            }
        }
        int n=0;
        while(fread(&se,sizeof(struct seat),1,f9))
        {
            n++;
        }
        fclose(f9);
        FILE *f12;
        f12=fopen("thirdshow.txt","r");
        int st[n];
        int c=0;
        struct seat f;
        while(fread(&f,sizeof(struct seat),1,f12))
        {
            st[c]=f.a;
            c++;
        }
        fclose(f12);
        int y=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int m=0;m<n;m++)
                {
                    if(st[m]==a[i][j])
                    {
                        y=1;
                        break;
                    }
                    else{
                        y=0;
                    }
                }
                if(y==0)
                {
                    printf("%d\t",a[i][j]);
                }
                else
                {
                    printf("B\t");
                }
            }
            printf("\n");
        }
        fclose(f9);
        tickets(3);
    }
    else if(t==4)
    {
        FILE *f9;
        int s=1;
        f9=fopen("fourthshow.txt","r");
        struct seat se;
        int a[9][16];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                a[i][j]=s;
                s++;
            }
        }
        int n=0;
        while(fread(&se,sizeof(struct seat),1,f9))
        {
            n++;
        }
        fclose(f9);
        FILE *f12;
        f12=fopen("fourthshow.txt","r");
        int st[n];
        int c=0;
        struct seat f;
        while(fread(&f,sizeof(struct seat),1,f12))
        {
            st[c]=f.a;
            c++;
        }
        fclose(f12);
        int y=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int m=0;m<n;m++)
                {
                    if(st[m]==a[i][j])
                    {
                        y=1;
                        break;
                    }
                    else{
                        y=0;
                    }
                }
                if(y==0)
                {
                    printf("%d\t",a[i][j]);
                }
                else
                {
                    printf("B\t");
                }
            }
            printf("\n");
        }
        fclose(f9);
        tickets(3);
    }
    else if(t==5)
    {
        FILE *f9;
        int s=1;
        f9=fopen("fifthshow.txt","r");
        struct seat se;
        int a[9][16];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                a[i][j]=s;
                s++;
            }
        }
        int n=0;
        while(fread(&se,sizeof(struct seat),1,f9))
        {
            n++;
        }
        fclose(f9);
        FILE *f12;
        f12=fopen("fifthshow.txt","r");
        int st[n];
        int c=0;
        struct seat f;
        while(fread(&f,sizeof(struct seat),1,f12))
        {
            st[c]=f.a;
            c++;
        }
        fclose(f12);
        int y=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int m=0;m<n;m++)
                {
                    if(st[m]==a[i][j])
                    {
                        y=1;
                        break;
                    }
                    else{
                        y=0;
                    }
                }
                if(y==0)
                {
                    printf("%d\t",a[i][j]);
                }
                else
                {
                    printf("B\t");
                }
            }
            printf("\n");
        }
        fclose(f9);
        tickets(5);
    }
}
void tickets(int x)
{
    if(x==1){
    printf("\nEnter number of tickets:");
    int n;
    scanf("%d",&n);
    FILE *f10;
    f10=fopen("fristshow.txt","r");
    struct seat st;
    int i=0;
    while(fread(&st,sizeof(struct seat),1,f10))
    {
        i++;
    }
    fclose(f10);
    if((144-i)>=n)
    {
        FILE *f11;
        f11=fopen("firstshow.txt","a");
        for(int j=0;j<n;j++)
        {
            struct seat t;
            printf("\nenter the seat number:");
            scanf("%d",&t.a);
            fwrite(&t,sizeof(struct seat),1,f11);
        }
        printf("\n cost of the ticket is 150");
        printf("\nTotal amount is : %d",n*150);
        printf("\n your ticket is booked sucessfully");
        fclose(f11);
    }
    else{
        printf("\nsorry %d number of tickets not avaliable");
    }
    }
    else if(x==2)
    {
    printf("\nEnter number of tickets:");
    int n;
    scanf("%d",&n);
    FILE *f10;
    f10=fopen("secondshow.txt","r");
    struct seat st;
    int i=0;
    while(fread(&st,sizeof(struct seat),1,f10))
    {
        i++;
    }
    fclose(f10);
    if((144-i)>=n)
    {
        FILE *f11;
        f11=fopen("secondshow.txt","a");
        for(int j=0;j<n;j++)
        {
            struct seat t;
            printf("\nenter the seat number:");
            scanf("%d",&t.a);
            fwrite(&t,sizeof(struct seat),1,f11);
        }
        printf("\n cost of the ticket is 150");
        printf("\nTotal amount is : %d",n*150);
        printf("\n your ticket is booked sucessfully");
        fclose(f11);
    }
    else{
        printf("\nsorry %d number of tickets not avaliable");
    }
    }
    else if(x==3)
    {
        printf("\nEnter number of tickets:");
    int n;
    scanf("%d",&n);
    FILE *f10;
    f10=fopen("thirdshow.txt","r");
    struct seat st;
    int i=0;
    while(fread(&st,sizeof(struct seat),1,f10))
    {
        i++;
    }
    fclose(f10);
    if((144-i)>=n)
    {
        FILE *f11;
        f11=fopen("thirdshow.txt","a");
        for(int j=0;j<n;j++)
        {
            struct seat t;
            printf("\nenter the seat number:");
            scanf("%d",&t.a);
            fwrite(&t,sizeof(struct seat),1,f11);
        }
        printf("\n cost of the ticket is 150");
        printf("\nTotal amount is : %d",n*150);
        printf("\n your ticket is booked sucessfully");
        fclose(f11);
    }
    else{
        printf("\nsorry %d number of tickets not avaliable");
    }
    }
    else if(x==4)
    {
        printf("\nEnter number of tickets:");
    int n;
    scanf("%d",&n);
    FILE *f10;
    f10=fopen("fourthshow.txt","r");
    struct seat st;
    int i=0;
    while(fread(&st,sizeof(struct seat),1,f10))
    {
        i++;
    }
    fclose(f10);
    if((144-i)>=n)
    {
        FILE *f11;
        f11=fopen("fourthshow.txt","a");
        for(int j=0;j<n;j++)
        {
            struct seat t;
            printf("\nenter the seat number:");
            scanf("%d",&t.a);
            fwrite(&t,sizeof(struct seat),1,f11);
        }
        printf("\n cost of the ticket is 150");
        printf("\nTotal amount is : %d",n*150);
        printf("\n your ticket is booked sucessfully");
        fclose(f11);
    }
    else{
        printf("\nsorry %d number of tickets not avaliable");
    }
    }
    else if(x==5)
    {
        printf("\nEnter number of tickets:");
    int n;
    scanf("%d",&n);
    FILE *f10;
    f10=fopen("fifthshow.txt","r");
    struct seat st;
    int i=0;
    while(fread(&st,sizeof(struct seat),1,f10))
    {
        i++;
    }
    fclose(f10);
    if((144-i)>=n)
    {
        FILE *f11;
        f11=fopen("fifthshow.txt","a");
        for(int j=0;j<n;j++)
        {
            struct seat t;
            printf("\nenter the seat number:");
            scanf("%d",&t.a);
            fwrite(&t,sizeof(struct seat),1,f11);
        }
        printf("\n cost of the ticket is 150");
        printf("\nTotal amount is : %d",n*150);
        printf("\n your ticket is booked sucessfully");
        fclose(f11);
    }
    else{
        printf("\nsorry %d number of tickets not avaliable");
    }
    }
}