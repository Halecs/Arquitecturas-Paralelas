#include<stdio.h>
#include <iostream>
 
int main()
{
   int n, i = 1, count, c;
 
   std::cout<<"Introduce el numero de primos deseado"<<std::endl;
   std::cin>>n;
 
   if ( n >= 1 )
   {
      std::cout<<"First "<<n<<" prime numbers are:\n";
   }  
   c = 1;
   for ( count = 1 ; count <= n ;  )
   {
      for (; c <= i - 1 ; c++ )
      {
         if ( i%c == 0 )
            break;
      }
      if ( c == i )
      {
         std::cout<<i<<std::endl;
         count++;
         c=2;
      }
      i++;
   }
return 0;
}