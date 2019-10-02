/* 単純交換ソート（第2版：交換回数による打切り） */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/* 単純交換ソート（第2版：交換回数による打切り） */
void bubble(int a[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++) {
    int exchg = 0;  /* パスにおける交換回数 */
    for (j = n - 1; j > i; j--)
      if (a[j - 1] > a[j]) {
        swap(int, a[j - 1], a[j]);
        exchg++;
      }
      if (exchg == 0) break; /* 交換が行われなかったら終了 */
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