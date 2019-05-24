/* 循環・重連結リストの利用例 */
#include <stdio.h>
#include "Member.h"
#include "CircDblLinkedList.h"

/* メニュー */
typedef enum {
  TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
  RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, NEXT, PREV, CLEAR
} Menu;

/* メニュー選択 */
Menu SelectMenu(void)
{
  int i, ch;
  char *mstring[] = {
    "先頭にノードを挿入", "末尾にノードを挿入", "先頭のノードを削除",
    "末尾のノードを削除", "着目ノードを表示", "着目ノードを削除",
    "番号で探索", "氏名で探索", "全ノードを表示",
    "着目ノードを後方へ", "着目ノードを前方へ", "全ノードを削除"
  };
  do {
    for (i = TERMINATE; i < CLEAR; i++) {
      printf("（%2d）%-18.18s ", i + 1, mstring[i]);
      if ((i % 3) == 2)
        putchar('\n');
    }
    printf("（ 0）終了：");
    scanf("%d", &ch);
  } while (ch < TERMINATE || ch > CLEAR);
  return (Menu)ch;
}

/* メイン */
int main(void)
{
  Menu menu;
  Dlist list;
  Initialize(&list);
  do {
    Member x;
    switch (menu = SelectMenu()) {
      /* 先頭にノードを挿入 */
      case INS_FRONT:
        x = ScanMember("先頭に挿入", MEMBER_NO | MEMBER_NAME);
        InsertFront(&list, &x);
        break;
      /* 末尾にノードを挿入 */
      case INS_REAR:
        x = ScanMember("末尾に挿入", MEMBER_NO | MEMBER_NAME);
        InsertRear(&list, &x);
        break;
      /* 先頭ノードを削除 */
      case RMV_FRONT:
        RemoveFront(&list);
        break;
      /* 末尾ノードを削除 */
      case RMV_REAR:
        RemoveRear(&list);
        break;
      /* 着目ノードのデータを表示 */
      case PRINT_CRNT:
        PrintLnCurrent(&list);
        break;
      /* 着目ノードを削除 */
      case RMV_CRNT:
        RemoveCurrent(&list);
        break;
      /* 番号による探索 */
      case SRCH_NO:
        x = ScanMember("探索", MEMBER_NO);
        if (Search(&list, &x, MemberNoCmp) != NULL)
          PrintLnCurrent(&list);
        else
          puts("その番号のデータはありません。");
        break;
      /* 氏名による探索 */
      case SRCH_NAME:
        x = ScanMember("探索", MEMBER_NAME);
        if (Search(&list, &x, MemberNameCmp) != NULL)
          PrintLnCurrent(&list);
        else
          puts("その名前のデータはありません。");
        break;
      /* 全ノードのデータを表示 */
      case PRINT_ALL:
        Print(&list);
        break;
      /* 着目ノードを一つ後方へ移動する */
      case NEXT:
        Next(&list);
        break;
      /* 着目ノードを一つ前方へ移動する */
      case PREV:
        Prev(&list);
        break;
      /* 全ノードを削除 */
      case CLEAR:
        Clear(&list);
        break;
      default:
        break;
    }
  } while (menu != TERMINATE);
  Terminate(&list);
  return 0;
}