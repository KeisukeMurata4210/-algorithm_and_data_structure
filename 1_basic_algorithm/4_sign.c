/* 読み込んだ整数値の符号（正 / 負 / 0）を判定 */
# include <stdio.h>

int main(void)
{
  int n;
  printf("整数を入力せよ：");
  scanf("%d", &n);

  if (n > 0)
    printf("それは正です。\n");
  else if (n < 0)
    printf("それは負です。\n");
  else
    printf("それは0です。\n");
  
  return 0;
}