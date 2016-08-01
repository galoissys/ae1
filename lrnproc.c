/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習機                                               */
/*  自己符号化機(Auto Encoder)                           */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	/* 構造体のメモリ確保 */
	
	// 学習データ構造体
	Lrndata *plrndata;
	plrndata = (Lrndata *)malloc(sizeof(Lrndata));
	//initldata(plrndata);
	
	// ニューロンの中間層及び出力層の重み構造体
	Whdata *pwhdata;
	Wodata *pwodata;
	pwhdata = (Whdata *)malloc(sizeof(Whdata));
	pwodata = (Wodata *)malloc(sizeof(Wodata));
	
	// 出力構造体
	Hd_output *phdo;
	Output *po;
	phdo = (Hd_output *)malloc(sizeof(Hd_output));
	po = (Output *)malloc(sizeof(Output));
	
	/* 構造体のメモリ確保完了 */
	
	
	// 学習データをセット
	setldata(plrndata);
	// debug_info
	getldata(plrndata);
	
	
	// 重みとしきい値の初期化
	init_wh(pwhdata);
	init_wo(pwodata);
	// debug_info
	get_wh(pwhdata);
	get_wo(pwodata);
	
	sleep(5);
	
	
	double err = 100;   // 誤差の初期値
	double err1 = 100;  // 誤差１の初期値
	int count = 0;
	
	int i=0, j=0, k=0;
	
	/* 学習 */
	while(err1 > LIMIT1){
		err1 = 0.0;
		for(k=0; k < OUT_NUM; ++k){
			err = 0.0;
			for(j=0; j < R_MAX; ++j){
				// 順方向の計算 
				forward(k, j, plrndata, pwhdata, pwodata, phdo, po);
				
				// 出力層重み調整
				olearn(k, j, plrndata, pwodata, phdo, po);
				
				// 中間層重み調整
				hlearn(k, j, plrndata, pwhdata, pwodata, phdo, po);
				
				// 誤差の積算
				// ldata[j][IN_NUM + k]は教師データ。乗算することで値を＋とし積算する。
				err += (po->output[k] - plrndata->ldata[j][IN_NUM + k]) * (po->output[k] - plrndata->ldata[j][IN_NUM + k]);
			}
			printf("count = %d\t k = %d\t err = %lf\n", count, k, err);
			err1 += err;
		}
		printf("count = %d\t err1 = %lf\n", count, err1);
		++count;
		// fprintf(stderr, "%d\t err1 = %lf\n", count, err1);
	} /* 学習終了 */
	
	
	// ニューロン中間層及び出力層の重みとしきい値の最終結果確認
	get_wh(pwhdata);
	get_wo(pwodata);
	
	
	// 学習データに対する出力
	for(i=0; i < R_MAX; ++i){
		printf("Num = %d \n", i);
		for(j=0; j < IN_NUM + OUT_NUM; ++j){
			// 学習データ出力
			printf("%.3lf ", plrndata->ldata[i][j]);
		}
		printf("\n");
		for(j=0; j< OUT_NUM; ++j){
			// 学習後の結果出力
			printf("%.3lf ", forward(j, i, plrndata, pwhdata, pwodata, phdo, po) );
		}
		printf("\n");
	}
	
	
	// メモリ解放
	free(plrndata);
	free(pwhdata);
	free(pwodata);
	free(phdo);
	free(po);
	
	
	return 0;
	
}


