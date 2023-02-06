/* recursive method */

fact(int n)
{
 int fact;
 if(n==1)
 return(1);
 else
 fact = n * fact(n-1);
 return(fact);
} 