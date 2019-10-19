/* マージソート */
#include <stdio.h>
#include <stdlib.h>

static int *buff; /* 作業用配列 */

/* マージソート（メイン部） */
static void __mergesort(int a[], int left, int right)
{
  if (left < right) {
    int center = (left + right) / 2;
    int p = 0;
    int i;
    int j = 0;
    int k = left;

    __mergesort(a, left, center);/* 前半部をマージソート */
    __mergesort(a, center + 1, right);/* 後半部をマージソート */

    for (i = left; i <= center; i++)
      buff[p++] = a[i];
    while (i <= right && j < p)/* aとbuffの両方とも、添字をはみ出ないことを保証 */
      a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
    while (j < p)/* a後半とbufで、a後半の方が先に末尾にたどり着いた場合、bufの残りをaの末尾に追加 */
      a[k++] = buff[j++];
  }
}

/* マージソート */
int mergesort_1(int a[], int n)
{
  if ((buff = calloc(n, sizeof(int))) == NULL)
    return -1;
  __mergesort(a, 0, n - 1); /* 配列全体をマージソート */
  free(buff);
  return 0;
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */

  puts("マージソート");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));

  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }

  mergesort_1(x, nx); /* 配列xをマージソート */

  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x); /* 配列を破棄 */
  return 0;
}