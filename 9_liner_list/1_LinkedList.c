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

/* 関数compareによってxと一致すると判定されるノードを探索 */
Node *Search(List *list, const Member *x, 
                          int compare(const Member *x, const Member *y))
{
  Node *ptr = list->head;
  while (ptr != NULL) {
    if (compare(&ptr->data, x) == 0) { /* キー値が一致 */
      list->crnt = ptr;
      return ptr;
    }
    ptr = ptr->next;
  }
  return NULL;
}

/* 先頭にノードを挿入 */
void InsertFront(List *list, const Member *x)
{
  Node *ptr = list->head;
  list->head = list->cnt = AllocNode();
  SetNode(list->head, x, ptr);
}

/* 末尾にノードを挿入 */
void InsertRear(List *list, const Member *x)
{
  if (list->head == NULL)/* 空であれば先頭に挿入する */
    InsertFront(list, x);
  else {
    Node *ptr = list->head;
    while (ptr->next != NULL)/* デフォルトは先頭を指しているから、nextがNULLつまり一番後ろにくるまで更新していく */
      ptr = ptr->next;
    ptr->next = list->crnt = AllocNode();
    SetNode(ptr->next, x, NULL);/* 後続ポインタがどこも指さないよう、NULLを渡す */
  }
}

/* 先頭ノードを削除 */
void RemoveFront(List *list)
{
  if (list->head != NULL) {/* リストが空でない時のみ */
    Node *ptr = list->head->next;/* 先頭ノードの後続ポインタ=２番目のノードへのポインタ */
    free(list->head);/* 動的に領域を確保したから、freeで開放すれば削除になる */
    list->head = list->crnt = ptr;/* 2番目が先頭になる ノード自体は後ろのポインタしか知らない */
  }
}

/* 末尾ノードを削除 */
void RemoveRear(List *list)
{
  if (list->head != NULL) {
    if ((list->head)->next == NULL) /* ノードが一つだけなら先頭を削除 */
      RemoveFront(list);
    else {
      Node *ptr = list->head;
      Node *pre;
      while (ptr->next != NULL) {
        pre = ptr;
        ptr = ptr->next;
      }
    }
  }
}