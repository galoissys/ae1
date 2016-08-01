/*********************************************************/
/*  ae1.h                                                */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  自己符号化機(Auto Encoder)                           */
/*                                                       */
/*********************************************************/
#ifndef _AE1_H_
#define _AE1_H_

#include "lcommon.h"
#include "lrndata.h"
#include "wdata.h"

/*  forward関数                               */
double forward(int o_cnt, int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  シグモイド関数                            */
// double f(double u);

/*  olearn関数                                */
void olearn(int o_cnt, int r_cnt, Lrndata *lrndata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  hlearn関数                                */
void hlearn(int o_cnt, int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);


#endif

