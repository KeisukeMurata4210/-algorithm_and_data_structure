/* int型のオブジェクトを動的に生成して破棄 */
# include <stdio.h>
# include <stdlib.h> /* calloc(), malloc(), free()などはこのヘッダー */

int main(void)
{
  int *x;
  x = calloc(1, sizeof(int));/* int型オブジェクト、要素数1。　確保できなければ空ポインタ（NULL）を返す */
  if (x == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    *x = 57; /* ポインタ型配列の、実際の値を操作するときは*をつける */
    printf("*x = %d\n", *x);
    free(x);
  }
  return 0;
}