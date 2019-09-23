#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

void quadratic_eqn(double  a, double  b, double  c)
{
    double d= b*b - 4*a*c;
    if (d < 0)
    {
     printf("First root = %.2lf + j%.2lf\n", -b/(2*a), sqrt(-d)/(2*a));
     printf("Second root = %.2lf - j%.2lf\n", -b/(2*a), sqrt(-d)/(2*a));
    }
   else
    {
      double  root1 = (-b + sqrt(d))/(2*a);
      double  root2 = (-b - sqrt(d))/(2*a);

      printf("First root = %.2lf\n", root1);
      printf("Second root = %.2lf\n", root2);
    }
}

int main()
{
    quadratic_eqn(1,2,6);
}
