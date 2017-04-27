/*
  >>~~ ACM PROBLEM ~~<<

  ID: 686
  Name: Goldbach's Conjecture (II)
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/


char isprime(int n)
{
  int i;
  for(i=2;i<=sqrt(n);i++)
    if(n%i==0)return 0;
  return 1;
}

int main()
{
 int n,count,i;
 while (scanf("%d",&n)!=-1)
 {
   if(!n)break;
   
   count=0;
   for(i=2;i<=n/2;i++)
     if(isprime(i) && isprime(n-i))
       count++;
   printf("%d\n",count);
 }
 return 0;
}
