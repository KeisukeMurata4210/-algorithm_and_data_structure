/* 単純挿入ソート */
#include <stdio.h>
#include <stdlib.h>

/* 単純挿入ソート */
void insertion(int a[], int n)
{
  int i, j;
  for (i = 1; i < n; i++) {/* 先頭2番目から末尾まで */
    int tmp = a[i];
    for (j = i; j > 0 && a[j - 1] > tmp; j--)/* 先頭に到達してない かつ 今見ている要素（j）が着目している要素より大きい 限り */
      a[j] = a[j - 1]; /* 一つ先頭側の要素を今見ている要素（j）に代入 */
    a[j] = tmp;/* 小さい要素が見つかった時点で、その要素はすでにa[j - 1]として一つ右側に代入ずみ。だからこの時点でのjの位置にtmpを代入すればOK */
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

  insertion(x, nx); /* 配列xを単純挿入ソート */

  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x); /* 配列を破棄 */
  return 0;
}