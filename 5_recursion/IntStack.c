/* int型スタックIntStack（ソース部）*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- スタックの初期化 ---*/
int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;								/* 配列の生成に失敗 */
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- スタックにデータをプッシュ ---*/
int Push(IntStack *s, int x)
{
	if (s->ptr >= s->max)						/* スタックは満杯 */
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- スタックからデータをポップ ---*/
int Pop(IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* スタックは空 */
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/*--- スタックからデータをピーク ---*/
int Peek(const IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* スタックは空 */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- スタックを空にする ---*/
void Clear(IntStack *s)
{
	s->ptr = 0;
}

/*--- スタックの容量 ---*/
int Capacity(const IntStack *s)
{
	return s->max;
}

/*--- スタックに積まれているデータ数 ---*/
int Size(const IntStack *s)
{
	return s->ptr;
}

/*--- スタックは空か ---*/
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
}

/*--- スタックは満杯か ---*/
int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
}

/*--- スタックからの探索 ---*/
int Search(const IntStack *s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* 頂上→底に線形探索 */
		if (s->stk[i] == x)
			return i;		/* 探索成功 */
	return -1;				/* 探索失敗 */
}

/*--- 全データの表示 ---*/
void Print(const IntStack *s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* 底→頂上に走査 */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- スタックの後始末 ---*/
void Terminate(IntStack *s)
{
	if (s->stk != NULL)
		free(s->stk);		/* 配列を破棄 */
	s->max = s->ptr = 0;
}
