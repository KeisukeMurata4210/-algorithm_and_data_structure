/* 各列に一個の王妃を配置する組み合わせを再帰的に列挙 */
#include <stdio.h>

int pos[8]; /* 各列の王妃の位置 */

void print(void)
{
  int i;
  for (i = 0; i < 8; i++)
    printf("%2d", pos[i]);
  putchar('\n');
}

void set(int i)
{
  int j;
  for (j = 0; j < 8; j++) {
    pos[i] = j;
    if (i == 7)
      print(); /* 全列に配置したら出力 */
    else
      set(i + 1);
  }
}

int main(void)
{
  set(0);
  return 0;
}