#pragma once
#define �鿴���� 1
#define �������� 2
#define ɾ������ 3
#define �޸����� 4
#define ��ѯ���� 5
#define �����ı� 6
#define �޸Ĳ������� 7
#define �޸����� 8
#define �˳� 9


#define NUM 100 //��ʼ���뱾����

typedef struct PASSWORD {
	char website[100];  //ʹ������ĵط�
	char userName[100];//�˺Ż��û���
	char passWord[100];//����
	char note[100];//��ע
}PASSWORD, *PPASSWORD;

extern int g_nNum;//��ǰ�����뱾����
//#ifdef __cplusplus
//extern "C" {
//#endif
//	int g_nNum = 0;
//#ifdef __cplusplus
//};
//#endif