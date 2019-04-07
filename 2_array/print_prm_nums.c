# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int detect_other_than_nums(const char *str)/* 文字列を渡すときは、先頭のポインタ（char型ポインタ）を渡す */
{
  int i;
  for (i = 0; i < strlen(str); i++) {/* ポインタは配列として扱える */
    if(str[i] < '0'|| str[i] > '9')
      return 1;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  /* コマンドライン引数の約数を全て出力する */
  int number, i;

  if (argc != 2) {
    printf("引数を一つ渡してください。\n");
    return 1;
  } else if (detect_other_than_nums(argv[1]) == 1) {
    printf("整数を入力してください。\n");
    return 1;
  }

  number = atoi(argv[1]);
  printf("整数%dの約数は。。。\n", number);
  for (i = 2; i < number; i++) {
    if (number % i != 0)
      continue;
    printf("%d\n", i);
  }
  return 0;
}