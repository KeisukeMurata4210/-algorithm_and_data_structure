/* bsearch関数を利用した降順に並んだ配列からの探索 */
#include <stdio.h>
#include <stdlib.h>

/* 整数を比較する関数（降順用） */
int int_cmpr(const int *a, const int *b)
{
  if (*a < *b)
    return 1;
  else if (*a > *b)
    return -1;
  else
    return 0;
}

int main(void)
{
  int i, nx, ky;
  int *x;/* 配列の先頭要素へのポインタ */
  int *p;/* 探索された要素へのポインタ */
  puts("bsearch関数による探索");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));
  printf("降順に入力してください。\n");
  printf("x[0]：");
  scanf("%d", &x[0]);
  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d]：", i);
      scanf("%d", &x[i]);
    } while (x[i] > x[i - 1]);
  }
  printf("探す値：");
  scanf("%d", &ky);
  p = bsearch(
    &ky,
    x,
    nx,
    sizeof(int),
    (int (*)(const void *, const void *))int_cmpr
  );
  if (p == NULL)
    puts("探索に失敗しました。");
  else
    printf("%dはx[%d]にあります。\n", ky, (int)(p - x));
  free(x);
  return 0;
}