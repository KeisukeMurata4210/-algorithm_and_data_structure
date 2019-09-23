/* チェイン法によるハッシュ（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/* ハッシュ関数（keyのハッシュ値を返す） */
static int hash(int key, int size)
{
  return key % size;
}

/* ノードの各メンバに値を設定 */
static void SetNode(Node *n, const Member *x, const Node *next)
{
  n->data = *x;   /* データ */
  n->next = next; /* 後続ノードへのポインタ */
}

/* ハッシュ表を初期化 */
int Initialize(ChainHash *h, int size)
{
  int i;
  if ((h->table = calloc(size, sizeof(Node *))) == NULL) {/* ハッシュ表は「Node型ポインタの配列」だった！！ */
    h->size = 0;
    return 0;
  }
  h->size = size;
  for (i = 0; i < size; i++) /* すべてのバケットを空にする */
    h->table[i] = NULL;
  return 1;
}

/* 探索 */
Node *Search(const ChainHash *h, const Member *x)
{
  int key = hash(x->no, h->size); /* 探索するデータのハッシュ値 */
  Node *p = h->table[key];   /* 着目ノード */
  while (p != NULL) {
    if (p->data.no == x->no)
      return p;
    p = p->next;  /* 後続ノードに着目 */
  }
  return NULL;   /* 探索失敗 */
}

/* データの追加 */
int Add(ChainHash *h, const Member *x)
{
  int key = hash(x->no, h->size);/* 追加するデータのハッシュ値 */
  Node *p = h->table[key];  /* 着目ノード */
  Node *temp;
  while (p != NULL) {
    if (p->data.no == x->no)
      return 1; /* このキーは登録済み　追加失敗 */
    p = p->next;
  } /* このwhileは「登録されたかどうか」を調べている */
  if ((temp = calloc(1, sizeof(Node))) == NULL)
    return 2;
  SetNode(temp, x, h->table[key]);/* 追加するノードに値を設定　‼︎先頭に割り込むということは、現状のハッシュ表の要素が後続ポインタになる！ */
  h->table[key] = temp;  /* ハッシュ表の要素を追加したノードへのポインタに変更 */
  return 0;
}

/* データの削除 */
int Remove(ChainHash *h, const Member *x)
{
  int key = hash(x->no, h->size); /* 削除するデータのハッシュ値 */
  Node *p = h->table[key];  /* 着目ノード */
  Node **pp = &h->table[key];/* 着目ノードへのポインタ */
  while (p != NULL) {
    if (p->data.no == x->no) {/* 見つけたら */
      *pp = p->next;
      free(p);
      return 0;
    }
    pp = &p->next;
    p = p->next;/* 後続ノードに着目 */
  }
  return 1;
}

/* ハッシュ表をダンプ */
void Dump(const ChainHash *h)/* ダンプとはすべて表示すること */
{
  int i;
  for (i = 0; i < h->size; i++) {
    Node *p = h->table[i];
    printf("%02d  ", i);
    while (p != NULL) {
      printf("→ %d（%s） ", p->data.no, p->data.name);
      p = p->next;
    }
    putchar('\n');
  }
}

/* 全データの削除 */
void Clear(ChainHash *h)
{
  int i;
  for (i = 0; i < h->size; i++) {
    Node *p = h->table[i];
    while (p != NULL) {
      Node *next = p->next;
      free(p);
      p = next;
    }
    h->table[i] = NULL;
  }
}

/* ハッシュ表を後始末 */
void Terminate(ChainHash *h)
{
  Clear(h); /* 全データを削除 */
  free(h->table);/* ハッシュ表用配列の */
  h->size = 0;
}