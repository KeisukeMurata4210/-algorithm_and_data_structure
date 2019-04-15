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
} List;