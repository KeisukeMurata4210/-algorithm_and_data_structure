#include <stdio.h>
#include "IntStack.h"

int main(void)
{
  IntStack s;
  if (Initialize(&s, 64) == -1) {
    puts("スタックの生成に失敗しました。");
    return 1;
  }
  while (1) {
    int menu, x;

    printf("現在のデータ数：%d / %d\n", Size(&s), Capacity(&s));
    printf("(1)プッシュ (2)ポップ (3)ピーク (4)表示 (0)終了：");
    scanf("%d", &menu);

    if (menu == 0) break;

    switch (menu){
      case 1: /* プッシュ */
        printf("データ：")
        scanf("%d", &x);
        if (Push(&s, &x) == -1)
          puts("\aエラー：プッシュに失敗しました。");
        break;
      
      case 2: /* ポップ */
        if (Pop(&s, &x) == -1)
          puts("\aエラー：ポップに失敗しました。");
        else
          printf("ポップしたデータは%dです。\n", x);
        break;

      case 3: /* ピーク */
        if (Peek(&s, &x) == -1)
          puts("\aエラー：ピークに失敗しました。");
        else
          printf("ピークしたデータは%dです。\n", x);
        break;
      
      case 4: /* 表示 */
        Print(&s);
        break;
    }
  }
  Terminate(&s);
  return 0;
}