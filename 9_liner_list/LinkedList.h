/* ポインタによる線形リスト（ヘッダ部） */
#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/* ノード */
typedef struct __node {
  Member         data;  /* データ */       
  struct __node *next;  /* 後続ポインタ（後続ノードへのポインタ） */
} Node;

/* 線形リスト */
typedef struct {
  Node *head; /* 先頭ノードへのポインタ */
  Node *crnt; /* 着目ノードへのポインタ */
} List;/* Listは先頭と現在位置を記録しておくだけ。実データにアクセスするときはListを経由する */

/* 線形リストを初期化 */
void Initialize(List *list);

/* 関数compareによってxと一致すると判定されるノードを探索 */
Node *Search(List *list, const Member *x, int compare(const Member *x, const Member *y));

/* 先頭にノードを挿入 */
void InsertFront(List *list, const Member *x);

/* 末尾にノードを挿入 */
void InsertRear(List *list, const Member *x);

/* 先頭ノードを削除 */
void RemoveFront(List *list);

/* 末尾ノードを削除 */
void RemoveRear(List *list);

/* 着目ノードを削除 */
void RemoveCurrent(List *list);

/* 全ノードを削除 */
void Clear(List *list);

/* 着目ノードのデータを表示 */
void PrintCurrent(const List *List);

/* 着目ノードのデータを表示（改行付き） */
void PrintLnCurrent(const List *List);

/* 全ノードのデータをリスト順に表示 */
void Print(const List *List);

/* 線形リストの後始末 */
void Terminate(List *list);

#endif