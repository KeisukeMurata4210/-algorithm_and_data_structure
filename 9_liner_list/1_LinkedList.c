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
      Node *ptr = list->head;/* 末尾ノード（現在のノードが指す、後続ノード） */
      Node *pre;             /* 末尾から2番目のノード（現在のノード） */
      while (ptr->next != NULL) {/* 後ろが無い、ってなったら終了 */
        pre = ptr;
        ptr = ptr->next;
      }
      pre->next = NULL;/* 末尾を削除するから、2番目ノードの後続ポインタはNULL */
      free(ptr);  /* 削除＝解放 */
      list->crnt = pre;/* 新しい末尾を現在のノードにする */
    }
  }
}

/* 着目ノードを削除 */
void RemoveCurrent(List *list)
{
  if (list->head != NULL) {
    if (list->crnt == list->head)/* 先頭に着目していれば */
      RemoveFront(list); /* 先頭を削除 */
    else {
      Node *ptr = list->head;
      while (ptr->next != list->crnt) /* 先頭から順番に、「今」のノードを探していく */
        ptr = ptr->next;/* ループが終わった時点で、ptrはcrntの一つ前のノードを指している */
      ptr->next = list->crnt->next;/* だから、ptrの後続ノードとして、削除するcrntの後続ノードを代入する */
      free(list->crnt);
      list->crnt = ptr;/* 削除した一つ前を今のノードにする */
    }
  }
}

/* 全ノードを削除 */
void Clear(List *list)
{
  while (list->head != NULL)/* 一番後ろを現在として渡さないと全部消しきれないのかな */
    RemoveFront(list);
  list->crnt = NULL;
}

/* 着目ノードのデータを表示 */
void PrintCurrent(const List *List)
{
  if (list->crnt == NULL)
    printf("着目ノードはありません。")
  else
    PrintMember(&list->crnt->data);
}

/* 着目ノードのデータを表示（改行付き） */
void PrintLnCurrent(const List *List)
{
  PrintCurrent(list);
  putchar('\n');
}

/* 全ノードのデータをリスト順に表示 */
void Print(const List *list)
{
  if (list->head == NULL)
    printf("ノードがありません。");/* 先頭から入れていく設計 */
  else {
    Node *ptr = list->head;
    puts("【一覧表】");
    while (ptr != NULL) {
      PrintLnMember(&ptr->data);
      ptr = ptr->next;
    }
  }
}

/* 線形リスとの後始末 */
void Terminate(List *list)
{
  Clear(list);
}