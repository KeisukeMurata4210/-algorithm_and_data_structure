/* 身体検査データ用構造体の配列 */
# include <stdio.h>

# define VMAX 21  /* 視力の最大値2.1 * 10 */

/* 身体検査データ型 */
typedef struct {
  char name[20]; /* 氏名 */
  int height;    /* 身長 */
  double vision; /* 視力 */
} PhysCheck;

/* 身長の平均値を求める */
double ave_height(const PhysCheck dat[], int n)/* 構造体型の配列ね */
{
  int i;
  double sum = 0;
  for (i = 0; i < n; i++)
    sum += dat[i].height;
  return sum / n;
}

/* 視力の分布を求める */
void dist_vision(const PhysCheck dat[], int n, int dist[])
{
  int i;
  for (i = 0; i < VMAX; i++)
    dist[i] = 0;
  for (i = 0; i < n; i++) /* nは人数 */
    if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
      dist[(int)(dat[i].vision * 10)]++;
}

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
  puts(" 氏名　　　       身長　視力　");
  puts("---------------------------");
  for (i = 0; i < nx; i++)
    printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);/* 構造体型の配列なら、要素にドット演算子でメンバにアクセスできる */
  printf("\n平均身長：%5.1fcm\n", ave_height(x, nx));
  dist_vision(x, nx, vdist);
  printf("\n視力の分布\n");
  for (i = 0; i < VMAX; i++)
    printf("%3.1f~：%2d人\n", i / 10.0, vdist[i]);/* 視力を10倍として扱った後/10.0とすることで計算のし易さを確保しつつ小数点を表現する */
  return 0;
}
/* 
%fの数字について
4.1の「4」は、「小数点も含めて4桁で表す」の意味
     「1」は、「小数点以下の」桁数
4.1だと「12.3」などになる
 */