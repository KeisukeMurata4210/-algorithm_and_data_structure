/* 線形リストの利用例 */
#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

/* メニュー */
typedef enum {
  TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
  RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

/* メニュー選択 */
Menu SelectMenu(void)
{
  int i, ch;
  char *mstring[] = {
    "先頭にノードを挿入", "末尾にノードを挿入", "先頭のノードを削除",
    "末尾のノードを削除", "着目ノードを表示", "着目ノードを削除",
    "番号で探索", "氏名で探索", "全ノードを表示",
    "全ノードを削除"
  };
  do {
    for (i = TERMINATE; i < CLEAR; i++) {
      printf("（%2d）%-18.18s ", i + 1, mstring[i]);
      if ((i % 3) == 2)/* iは0から始まるから、余りが2＝改行して4つ目 */
        putchar('\n');
    }
    printf("（ 0）終了　：");
    scanf("%d", &ch);
  } while (ch < TERMINATE || ch > CLEAR)
  return (Menu)ch;
}

/* メイン */
int main(void)
{
  Menu menu;
  List list;
  Initialize(&list); /* 線形リストの初期化 */
  do {
    Member x;
    switch (menu = SelectMenu()){
      case /* constant-expression */:
        /* code */
        break;
    
      default:
        break;
    }
  }
}