/* int型スタックIntStack（ヘッダ部）*/

#ifndef ___IntStack
#define ___IntStack

/*--- スタックを実現する構造体 ---*/
typedef struct {
	int max;		/* スタックの容量 */
	int ptr;		/* スタックポインタ */
	int *stk;		/* スタック本体（の先頭要素へのポインタ） */
} IntStack;

/*--- スタックの初期化 ---*/
int Initialize(IntStack *s, int max);

/*--- スタックにデータをプッシュ ---*/
int Push(IntStack *s, int x);

/*--- スタックからデータをポップ ---*/
int Pop(IntStack *s, int *x);

/*--- スタックからデータをピーク ---*/
int Peek(const IntStack *s, int *x);

/*--- スタックを空にする ---*/
void Clear(IntStack *s);

/*--- スタックの容量 ---*/
int Capacity(const IntStack *s);

/*--- スタック上のデータ数 ---*/
int Size(const IntStack *s);

/*--- スタックは空か ---*/
int IsEmpty(const IntStack *s);

/*--- スタックは満杯か ---*/
int IsFull(const IntStack *s);

/*--- スタックからの探索 ---*/
int Search(const IntStack *s, int x);

/*--- 全データの表示 ---*/
void Print(const IntStack *s);

/*--- スタックの後始末 ---*/
void Terminate(IntStack *s);

#endif
