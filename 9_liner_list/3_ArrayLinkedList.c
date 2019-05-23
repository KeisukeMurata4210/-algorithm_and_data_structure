/* カーソルによる線形リスト（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/* 挿入するレコードのインデックスを求める */
static Index GetIndex(List *list)
{
  if (list->deleted == NULL) /* 削除レコードがない場合 */
    return ++(list->max);
  else {
    Index rec = list->deleted;
    list->deleted = list->n[rec].Dnext;/* Node型ポインタを要素に持つ配列n */
    return rec;
  }
}

/* 指定したレコードを削除リストに登録する */
static void DeleteIndex(List *list, Index idx)
{
  if (list->deleted = NULL) {/* 削除レコードがない場合 */
    list->deleted = idx;
    list->n[idx].Dnext = NULL;
  } else {
    Index ptr = list->deleted;
    list->deleted = idx;
    list->n[idx].Dnext = ptr;
  }
}

/* nの指すノードの各メンバに値を設定 */
static void SetNode(Node *n, const Member *x, Index next)
{
  n->data = *x;
  n->next = next;
}

/* 線形リストを初期化（最大要素数はsize） */
void Initialize(List *list, int size)
{
  list->n = calloc(size, sizeof(Node));
  list->head = NULL;
  list->crnt = NULL;
  list->max = NULL;
  list->deleted = NULL;
}

/* 関数compareによってxと一致すると判定されるノードを探索 */
Index Search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
  Index ptr = list->head;
  while (ptr != NULL) {
    if (compare(&list->n[ptr].data, x) == 0) {
      list->crnt = ptr;
      return ptr;/* 探索成功 */
    }
    ptr = list->n[ptr].next;/* 後ろ、後ろとずらしていく。末尾に来るとnext==NULL */
  }
  return NULL;
}

/* 先頭にノードを挿入 */
void InsertFront(List *list, const Member *x)
{
  Index ptr = list->head;
  list->head = list->crnt = GetIndex(list);
  SetNode(&list->n[list->head], x, ptr);
}

/* 末尾にノードを挿入 */
void InsertRear(List *list, const Member *x)
{
  if (list->head == NULL)
    InsertFront(list, x);
  else {
    Index ptr = list->head;
    while (list->n[ptr].next != NULL)/* 末尾に移動している */
      ptr = list->n[ptr].next;
    list->n[ptr].next = list->crnt = GetIndex(list);
    SetNode(&list->n[list->n[ptr].next], x, NULL);
  }
}

/* 先頭ノードを削除 */
void RemoveFront(List *list)
{
  if (list->head != NULL) {
    Index ptr = list->n[list->head].next;
    DeleteIndex(list, list->head);
    list->head = list->crnt = ptr;/* 後続ノードを先頭にする */
  }
}

/* 末尾ノードを削除 */
void RemoveRear(List *list)
{
  if (list->head != NULL) {
    if (list->n[list->head].next == NULL)
      RemoveFront(list);
    else {
      Index ptr = list->head;
      
    }
  }
}

/* 着目ノードを削除 */
void RemoveCurrent(List *list);

/* 全ノードを削除 */
void Clear(List *list);

/* 着目ノードのデータを表示 */
void PrintCurrent(const List *list);

/* 着目ノードのデータを表示（改行つき） */
void PrintLnCurrent(const List *list);

/* 全ノードのデータを表示 */
void Print(const List *list);

/* 線形リストの後始末 */
void Terminate(List *list);