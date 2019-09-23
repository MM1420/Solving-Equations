#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int ara[4];
int *p=ara;
double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
char equ1[20],equ2[20],equ3[20];


void ExtractCoeff(char *s);
double determinant(double at1,double bt1,double ct1,double at2,double bt2,double ct2,double at3,double bt3,double ct3);
void cramersrule(double tempa1,double tempb1,double tempc1,double tempd1,double tempa2,double tempb2,double tempc2,double tempd2,double tempa3,double tempb3,double tempc3,double tempd3);
//double GaussianElimination();
/*x+y-z=6
3x-2y+z=-5
x+3y-2z=14*/

int main()
{
    //printf("Equation solver prepared to solve!!\n\n");
    printf("Instructions:\n1=>Enter your equations in \"Ax+By+Cz=D\" form.\n2=>A,B,C,D must be integers.\n3=>Unusual characters must be avoided.\n4=>Space must be avoided.\n");
    printf("\nEnter your Equations:\n\n");

    printf("Equation 1: ");
    gets(equ1);

    ExtractCoeff(equ1);
    a1=(double)p[0],b1=(double)p[1],c1=(double)p[2],d1=(double)p[3];

    printf("Equation 2: ");
    gets(equ2);

    ExtractCoeff(equ2);
    a2=(double)p[0],b2=(double)p[1],c2=(double)p[2],d2=(double)p[3];

    printf("Equation 3: ");
    gets(equ3);

    ExtractCoeff(equ3);
    a3=(double)p[0],b3=(double)p[1],c3=(double)p[2],d3=(double)p[3];

    cramersrule(a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3);

}


void ExtractCoeff(char *s)
{
    int i,j,k;
    int l=strlen(s);
    int sum=0,n=1;
    for(i=0;s[i]!='=';i++)
    {
        if(s[i]=='x')
        {
            if(i==0)
                ara[0]=1;
            else if(s[i-1]=='-')
                ara[0]=-1;
            else if(s[i-1]=='+')
                ara[0]=1;
            else{
                for(j=i-1;j>=0&&isdigit(s[j]);){
                    sum+=(s[j]-'0')*n;
                    j--;
                    n*=10;
                }
                j++;
                if(s[j-1]=='-')
                    sum*=(-1);
                ara[0]=sum;
                sum=0,n=1;
            }
        }
        else if(s[i]=='y')
        {
            if(i==0)
                ara[1]=1;
            else if(s[i-1]=='-')
                ara[1]=-1;
            else if(s[i-1]=='+')
                ara[1]=1;
            else{
                for(j=i-1;j>=0&&isdigit(s[j]);){
                    sum+=(s[j]-'0')*n;
                    j--;
                    n*=10;
                }
                j++;
                if(s[j-1]=='-')
                    sum*=(-1);
                ara[1]=sum;
                sum=0,n=1;
            }
        }
        else if(s[i]=='z')
        {
            if(i==0)
                ara[2]=1;
            else if(s[i-1]=='-')
                ara[2]=-1;
            else if(s[i-1]=='+')
                ara[2]=1;
            else{
                for(j=i-1;j>=0&&isdigit(s[j]);){
                    sum+=(s[j]-'0')*n;
                    j--;
                    n*=10;
                }
                j++;
                if(s[j-1]=='-')
                    sum*=(-1);
                ara[2]=sum;
                sum=0,n=1;
            }
        }
    }
    for(i=l-1;s[i]!='=';){
        sum+=(s[i]-'0')*n;
        if(s[i-1]=='-'){
            sum*=(-1);
            break;
        }
        i--;
        n*=10;
    }
    ara[3]=sum;
    return;
}

double determinant(double at1,double bt1,double ct1,double at2,double bt2,double ct2,double at3,double bt3,double ct3)
{
     double det = (at1*((bt2*ct3)-(bt3*ct2))) - (bt1*((at2*ct3)-(at3*ct2))) + (ct1*((at2*bt3)-(at3*bt2)));
     return det;
}

void cramersrule(double tempa1,double tempb1,double tempc1,double tempd1,double tempa2,double tempb2,double tempc2,double tempd2,double tempa3,double tempb3,double tempc3,double tempd3)
{
    double DET,detX,detY,detZ,x,y,z;

    DET = determinant(tempa1,tempb1,tempc1,tempa2,tempb2,tempc2,tempa3,tempb3,tempc3);
    detX= determinant(tempd1,tempb1,tempc1,tempd2,tempb2,tempc2,tempd3,tempb3,tempc3);
    detY= determinant(tempa1,tempd1,tempc1,tempa2,tempd2,tempc2,tempa3,tempd3,tempc3);
    detZ= determinant(tempa1,tempb1,tempd1,tempa2,tempb2,tempd2,tempa3,tempb3,tempd3);

    if(DET==0)
    printf("\nIt has no solutions!\n");
    else{
    x = detX/DET;
    y = detY/DET;
    z = detZ/DET;

    printf("\nSolutions:\n");
    printf("\nx = %.2lf,\ty = %.2lf,\tz = %.2lf\n",x,y,z);}
}
