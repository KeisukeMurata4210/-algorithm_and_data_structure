/* 三つの整数値を読み込んで中央値を求める */
# include <stdio.h>

/* a,b,cの中央値を求める */
int med3(int a, int b, int c)
{/* 「>=」/「<」の2択で絞り込む  */
  /* 「中央値」だから決定木を全て書くのではなく、中央が確定した時点で返却する */
  if (a >= b) {
    if (b >= c)/* a >= b >= c */
      return b;
    else if (a <= c) /* c >= a >= b */
      return a;
    else             /* どちらでもないから残ったc */
      return c;
  } else if (a > c) /* ここ以降は「b > a」が決定している */
    return a;    /* b > a > c */
  else if (b > c)   /* ここ以降は「b > a」「c >= a」が決定している → 重要なのはbとcの大小関係 */
    return c;
  else
    return b;
}

int main(void)
{
  int a, b, c;

  printf("三つの整数の中央値を求めます。\n");
  printf("aの値："); scanf("%d", &a);
  printf("bの値："); scanf("%d", &b);
  printf("cの値："); scanf("%d", &c);

  printf("中央値は%dです。\n", med3(a, b, c));

  return 0;
}