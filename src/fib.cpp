#include "../include/fib.h"

int fibonacci::fibCal(int n)
{
  if (n < 2)
    return n;
  return fibCal(n - 1) + fibCal(n - 2);
}