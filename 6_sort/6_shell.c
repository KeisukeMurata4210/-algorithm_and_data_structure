/* シェルソート */
#include <stdio.h>
#include <stdlib.h>

/* シェルソート */
void shell(int a[], int n)
{
  int i, j, h;
  for (h = n / 2; h > 0; h /= 2) {/* すごい。ループの条件にソートする間隔を使う */
    for (i = h; i < n; i++) {
      int tmp = a[i];
      for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
        a[j + h] = a[j];
      a[j + h] = tmp;
    }
  }
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */
  puts("単純挿入ソート");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int)); /* 要素数nxのint型配列を生成 */

  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }

  shell(x, nx); /* 配列xをシェルソート */

  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x); /* 配列を破棄 */
  return 0;
}