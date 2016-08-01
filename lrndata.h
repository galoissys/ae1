/*********************************************************/
/*  lrndata.h                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習データセット                                     */
/*                                                       */
/*********************************************************/
#ifndef _LRNDATA_H_
#define _LRNDATA_H_

#include <stdio.h>
#include <string.h>
#include "lcommon.h"

/*  学習データセット データ構造                          */

typedef struct{
	double ldata[R_MAX][IN_NUM + OUT_NUM];  // IN_NUM + teacher_data(OUT_NUM)
} Lrndata;

/*  学習データセット 関数                                */
void initldata(Lrndata *lrndata);
void setldata(Lrndata *lrndata);
void getldata(Lrndata *lrndata);


#endif

