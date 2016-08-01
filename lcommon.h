/*********************************************************/
/*  lcommon.h                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  自己符号化機(Auto Encoder)                           */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _LCOMMON_H_
#define _LCOMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define IN_NUM 9      /* 入力層セル数 */
#define HD_NUM 7      /* 中間層セル数 */
#define OUT_NUM 9     /* 出力層人口ニューロン数 */

#define R_MAX 6       /* トレーニングデータ件数 */

#define ALPHA 10      /* 学習係数 */

#define LIMIT 0.001   /* 誤差上限値 */
#define LIMIT1 0.01   /* 誤差上限値１ */


#endif

