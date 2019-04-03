#include <iostream>
#include <string>
#include <omp.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int num, cont = 1, primo = 1, d = 1;
  double time, t1, t2;
  // clock_t t1, t2;

  cout<<"Ingrese la cantidad de números primos que desee:";
  cin>>num;

  t1 = omp_get_wtime();
#pragma parallel shared(cont, num)
  {
  while(cont <= num)
  {
    if (primo % d == 0)
    {
      if (primo == d)
      {
        cout<<primo;
        cout<<", ";
        cont++;
      }
      d = 2;
      primo++;
    }
    else
    {
      d++;
    }
  }
  cout<<" "<<endl;
}
  t2 = omp_get_wtime();

  time = (t2 - t1);

  cout<<time<<endl;

  return 0;
}