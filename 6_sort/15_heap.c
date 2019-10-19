/* ヒープソート */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do {type t = x; x = y; y = t;} while (0)

/* a[left] ~ a[right]をヒープ化 */
static void downheap(int a[], int left, int right)
{
  int temp = a[left]; /* 根。！！一番左が根、最大値になって、一番右が最小値になる！！ */
  int child;
  int parent;

  for (parent = left; parent < (right + 1) / 2; parent = child) {
    int cl = parent * 2 + 1; /* 左の子 */
    int cr = cl + 1; /* 右の子 */
    child = (cr <= right && a[cr] > a[cl]) ? cr : cl; /* 大きい方 */
    if (temp >= a[child])
      break;
    a[parent] = a[child];
  }
  a[parent] = temp;
}

/* ヒープソート */
void heapsort_1(int a[], int n)
{
  int i;
  for (i = (n - 1) / 2; i >= 0; i--)/* ここで配列をヒープ化する */
    downheap(a, i, n - 1);
  for (i = n - 1; i > 0; i--) {
    swap(int, a[0], a[i]);/* 根と末尾を交換して、、 */
    downheap(a, 0, i - 1);/* まだソートされていない範囲をヒープする。の繰り返し */
  }
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */

  puts("ヒープソート");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));

  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }

  heapsort_1(x, nx); /* 配列xをヒープソート */
  
  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x); /* 配列を破棄 */
  return 0;
}