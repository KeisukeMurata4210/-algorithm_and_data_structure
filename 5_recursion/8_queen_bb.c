/* 各行・各列に１個の王妃を配置する組み合わせを再帰的に列挙 */
#include <stdio.h>

int flag[8]; /* 各列に王妃が配置済みか */
int pos[8];  /* 各列の王妃の位置 */

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
    if (!flag[j]) { /* 未配置=0=!だからtrue */
      pos[i] = j;
      if (i == 7)
        print();
      else {
        flag[j] = 1;
        set(i + 1);
        flag[j] = 0;
      }
    }
  }
}

int main(void)
{
  int i;
  for (i = 0; i < 8; i++)
    flag[i] = 0;
  set(0);
  return 0;
}