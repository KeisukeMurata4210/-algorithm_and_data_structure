/* qsort関数を利用して整数配列の要素を値の昇順にソート */
#include <stdio.h>
#include <stdlib.h>

/* int型の比較関数（昇順ソート用） */
int int_cmp(const int *a, const int *b)
{
  if (*a < *b)
    return -1;
  else if (*a > *b)
    return 1;
  else
    return 0;
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */
  printf("qsortによるソート\n");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int)); /* 要素数nxのint型配列を生成 */

  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }

  qsort(
    x,           /* 配列 */
    nx,          /* 要素数 */
    sizeof(int), /* 要素の大きさ */
    (int (*)(const void *, const void *))int_cmp /* 比較関数。 */
  );

  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x);
  return 0;
}