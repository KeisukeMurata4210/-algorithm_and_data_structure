/* ソート済み配列をマージ */
#include <stdio.h>

/* ソート済み配列aとbをマージしてcに格納 */
void merge(const int a[], int na, const int b[], int nb, int c[])
{
  int pa = 0;
  int pb = 0;
  int pc = 0;

  while (pa < na && pb < nb)
    c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
  while (pa < na)/* bが先に末尾に到達した場合→aの残りをcに代入する */
    c[pc++] = a[pa++];
  while (pb < nb)/* aが先に末尾に到達した場合→bの残りをcに代入する */
    c[pc++] = b[pb++];
}

int main(void)
{
  int i, na, nb;
  int *a, *b, *c;

  printf("aの要素数："); scanf("%d", &na);
  printf("bの要素数："); scanf("%d", &nb);

  a = calloc(na, sizeof(int));
  b = calloc(nb, sizeof(int));
  c = calloc(na + nb, sizeof(int)); /* そっか。確かに足せばいいんだ。 */

  printf("a[0]：");
  scanf("%d", &a[0]);/* なんでだっけ。 */
  for (i = 1; i < na; i++) {
    do {
      printf("a[%d]：", i);
      scanf("%d", &a[i]);
    } while (a[i] < a[i - 1]);/* 「i - 1」がエラーにならないために添字0はループ外で代入する */
  }

  printf("b[0]：");
  scanf("%d", &b[0]);
  for (i = 1; i < nb; i++) {
    do {
      printf("b[%d]：", i);
      scanf("%d", &b[i]);
    } while (b[i] < b[i - 1]);
  }

  /* 配列aとbをマージしてcに格納 */
  merge(a, na, b, nb, c);

  puts("配列aとbをマージして配列cに格納しました。");
  for (i = 0; i < na + nb; i++)
    printf("c[%2d] = %2d\n", i, c[i]);
  free(a); free(b); free(c);
  return 0;
}