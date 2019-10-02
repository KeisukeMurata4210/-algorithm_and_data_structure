/* 単純交換ソート */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/* 単純交換ソート */
void bubble(int a[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--)
      if (a[j - 1] > a[j])
        swap(int, a[j - 1], a[j]);
  }
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */
  puts("単純交換ソート");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int)); /* 要素数nxのint型配列を生成 */

  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }
  bubble(x, nx); /* 配列xを単純交換ソート */

  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x); /* 配列を破棄 */
  return 0;
}