/*
最大公約数を求める方法は、
長方形を正方形で埋め尽くす作業と同じ
*/
#include <stdio.h>

int gcd(int x, int y)
{
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int main(void)
{
  int x, y;
  puts("二つの整数の最大公約数を求めます。\n");
  printf("整数を入力せよ：");
  scanf("%d", &x);
  printf("整数を入力せよ：");
  scanf("%d", &y);
  printf("最大公約数は%dです。\n", gcd(x, y));
  return 0;
}