/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�@                                               */
/*  ���ȕ������@(Auto Encoder)                           */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	/* �\���̂̃������m�� */
	
	// �w�K�f�[�^�\����
	Lrndata *plrndata;
	plrndata = (Lrndata *)malloc(sizeof(Lrndata));
	//initldata(plrndata);
	
	// �j���[�����̒��ԑw�y�яo�͑w�̏d�ݍ\����
	Whdata *pwhdata;
	Wodata *pwodata;
	pwhdata = (Whdata *)malloc(sizeof(Whdata));
	pwodata = (Wodata *)malloc(sizeof(Wodata));
	
	// �o�͍\����
	Hd_output *phdo;
	Output *po;
	phdo = (Hd_output *)malloc(sizeof(Hd_output));
	po = (Output *)malloc(sizeof(Output));
	
	/* �\���̂̃������m�ۊ��� */
	
	
	// �w�K�f�[�^���Z�b�g
	setldata(plrndata);
	// debug_info
	getldata(plrndata);
	
	
	// �d�݂Ƃ������l�̏�����
	init_wh(pwhdata);
	init_wo(pwodata);
	// debug_info
	get_wh(pwhdata);
	get_wo(pwodata);
	
	sleep(5);
	
	
	double err = 100;   // �덷�̏����l
	double err1 = 100;  // �덷�P�̏����l
	int count = 0;
	
	int i=0, j=0, k=0;
	
	/* �w�K */
	while(err1 > LIMIT1){
		err1 = 0.0;
		for(k=0; k < OUT_NUM; ++k){
			err = 0.0;
			for(j=0; j < R_MAX; ++j){
				// �������̌v�Z 
				forward(k, j, plrndata, pwhdata, pwodata, phdo, po);
				
				// �o�͑w�d�ݒ���
				olearn(k, j, plrndata, pwodata, phdo, po);
				
				// ���ԑw�d�ݒ���
				hlearn(k, j, plrndata, pwhdata, pwodata, phdo, po);
				
				// �덷�̐ώZ
				// ldata[j][IN_NUM + k]�͋��t�f�[�^�B��Z���邱�ƂŒl���{�Ƃ��ώZ����B
				err += (po->output[k] - plrndata->ldata[j][IN_NUM + k]) * (po->output[k] - plrndata->ldata[j][IN_NUM + k]);
			}
			printf("count = %d\t k = %d\t err = %lf\n", count, k, err);
			err1 += err;
		}
		printf("count = %d\t err1 = %lf\n", count, err1);
		++count;
		// fprintf(stderr, "%d\t err1 = %lf\n", count, err1);
	} /* �w�K�I�� */
	
	
	// �j���[�������ԑw�y�яo�͑w�̏d�݂Ƃ������l�̍ŏI���ʊm�F
	get_wh(pwhdata);
	get_wo(pwodata);
	
	
	// �w�K�f�[�^�ɑ΂���o��
	for(i=0; i < R_MAX; ++i){
		printf("Num = %d \n", i);
		for(j=0; j < IN_NUM + OUT_NUM; ++j){
			// �w�K�f�[�^�o��
			printf("%.3lf ", plrndata->ldata[i][j]);
		}
		printf("\n");
		for(j=0; j< OUT_NUM; ++j){
			// �w�K��̌��ʏo��
			printf("%.3lf ", forward(j, i, plrndata, pwhdata, pwodata, phdo, po) );
		}
		printf("\n");
	}
	
	
	// ���������
	free(plrndata);
	free(pwhdata);
	free(pwodata);
	free(phdo);
	free(po);
	
	
	return 0;
	
}


