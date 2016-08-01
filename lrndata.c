/*********************************************************/
/*  lrndata.c                                            */
/*                                                       */
/*********************************************************/
#include "lrndata.h"

/*********************************************************/
/*  initldataŠÖ”                                         */
/*********************************************************/
void initldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	memset(lrndata, 0, sizeof(Lrndata));
	
	for(i=0; i < R_MAX; ++i){
		for(j=0; j < IN_NUM + OUT_NUM; ++j){
			lrndata->ldata[i][j] = 0.0;
		}
	}
	
	
}


/*********************************************************/
/*  setldataŠÖ”                                         */
/*********************************************************/
void setldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	for(i=0; i < R_MAX; ++i){
		for(j=0; j < IN_NUM + OUT_NUM; ++j){
			scanf("%lf", &lrndata->ldata[i][j]);
		}
	}
	
}


/*********************************************************/
/*  getldataŠÖ”                                         */
/*********************************************************/
void getldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	printf("*** Learnning Data Set ***\n");
	
	for(i=0; i < R_MAX; ++i){
		printf("Num = %d\n", i+1);
		printf("** INPUT Data **\n");
		for(j=0; j < IN_NUM; ++j){
			printf("%lf ", lrndata->ldata[i][j]);
		}
		printf("\n** Teacher Data **\n");
		for(j=IN_NUM; j < IN_NUM + OUT_NUM; ++j){
			printf("%lf ", lrndata->ldata[i][j]);
		}
		printf("\n");
	}
	
}



