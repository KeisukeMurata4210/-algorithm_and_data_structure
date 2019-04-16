/* ポインタによる線形リスト（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/* 一つのノードを動的に生成 */
static Node *AllocNode(void)
{
  return calloc(1, sizeof(Node));
}

/* nの指すノードの各メンバに値を設定 */
static void SetNode(Node *n, const Member *x, const Node *next)
{
  n->data = *x;   /* データ */
  n->next = next; /* 後続ポインタ */
}

/*  線形リストを初期化 */
void Initialize(List *list)
{
  list->head = NULL;/* 先頭ノード */
  list->crnt = NULL;/* 着目ノード */
}