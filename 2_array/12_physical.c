/* 身体検査データ用構造体の配列 */
# include <stdio.h>

# define VMAX 21  /* 視力の最大値2.1 * 10 */

/* 身体検査データ型 */
typedef struct {
  char name[20]; /* 氏名 */
  int height;    /* 身長 */
  double vision; /* 視力 */
} PhysCheck;


int main(void)
{
  int i;
  PhysCheck x[] = { /* 構造体型の配列 */
    {"AKASAKA Tadao",     162, 0.3}, /* 代入の時は定義と同じく{}で囲む */
    {"KATOH Tomiaki",     173, 0.7},
    {"SAITOH Syouji",     175, 2.0},
    {"TAKEDA Shinya",     171, 1.5},
    {"NAGAHAMA Masaki",   168, 0.4},
    {"HAMADA Tetsuaki",   174, 1.2},
    {"MATSUTOMI Akio",    169, 0.8},
  };
  int nx = sizeof(x) / sizeof(x[0]); /* 人数 */
  int vdist[VMAX];    /* 視力の分布 */

  puts("   身体検査一覧表　　　");
  puts(" 氏名　　　身長　視力　");
  puts("--------------------");
  for (i = 0; i < nx; i++)
}