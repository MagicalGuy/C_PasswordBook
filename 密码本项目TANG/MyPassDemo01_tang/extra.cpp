#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#include"ctrl.h"

//��ȡ���뱾��������
char* readPass(char* str) {
	FILE* fp;

	if (fopen_s(&fp, "pass.i", "r") != 0) {
		printf("��һ��ʹ�ã���ʼ���ļ��У���\n");
		//exit(1);
	}


	else {
		fscanf_s(fp, "%s", str, 20);
		for (int i = 0; str[i] != '\0'; i++) str[i] ^= 5;//��ȡ����
		fclose(fp);
		return str;
	}
	return NULL;
}

//�������뱾��������
void savePass(char * str1) {
	FILE* fp;

	if (fopen_s(&fp, "pass.i", "w") != 0) {
		printf("������ʧ��\n");
		system("pause");
		exit(1);
	}
	for (int i = 0; str1[i] != '\0'; i++) str1[i] ^= 5;  //д���ļ�����
	fprintf(fp, "%s", str1);
	fclose(fp);
}

//�޸����뱾��������
void modifyPass() {
	char str[20];
	char* pass = readPass(str);

	int flag = 1;
	while (flag) {
		char str1[20];
		printf("ԭ��������Ϊ��%s\n", pass);
		printf("�������µĲ������룺\n");
		scanf_s("%s", str1, 20);
		char str2[20];
		printf("���ٴ�����ȷ�����룺\n");
		scanf_s("%s", str2, 20);
		//gets_s(str2);
		if (str1 == "" || str2 == "") { printf("����Ϊ�գ��޸�ʧ�ܣ�"); flag = 0; }
		else if (strcmp(str1, str2) == 0) {
			savePass(str1);
			printf("�޸ĳɹ���");
			flag = 0;
		}
		else { printf("����������\n"); flag = 1; }
	}

	system("pause");
	system("cls");
}


void initPlayPass() {
	FILE* fp;
	char str[20] = "1234";
	if (fopen_s(&fp, "pass.i", "w") != 0) {
		printf("������ʧ��\n");
		system("pause");
		exit(1);
	}
	for (int i = 0; str[i] != '\0'; i++) str[i] ^= 5;
	fprintf(fp, "%s", str);
	fclose(fp);
}


//��¼����
void loginOS() {

	printf("=====����ӭʹ�ø������뱾��=====\n");

	printf("��ʹ���������뱾��������(��ʼ���룺1234)��\n");
	char _ch[20];
	//scanf_s("%s", _ch, 20);
	gets_s(_ch);
	char str[20];

	if (readPass(str) == NULL) {
		initPlayPass();
	}

	if (strcmp(_ch, readPass(str)) != 0) {
		//	printf("%s\n", readPass());
		printf("���벻��ȷ�˳�ϵͳ������\n");
		system("pause");
		return;
	}

	system("pause");
	system("cls");
	printf("��¼�ɹ���");
	initPassword();
}

//�޸����뱾����
void alterVolume(PASSWORD* ppwd, int *ncount) {
	printf("ԭʼ���뱾������СΪ��%d\n", g_nNum);
	printf("�����������޸ĵĴ�С:\n");

	scanf_s("%d", &g_nNum);

	if (g_nNum == 0) { printf("����Ϊ�գ��޸�ʧ�ܣ�\n"); return; }

	savePwd(ppwd, ncount);
	system("pause");
	system("cls");
	printf("�޸ĳɹ���");
}

//�������뱾��������
void initPassword() {
	//PASSWORD pPwd[NUM];
	PASSWORD*  pPwd = nullptr;
	int pnCount = 0;//��ǰ�������
	g_nNum = 0;//��ǰ���뱾����
	PASSWORD * ppPwd = readPwd(pPwd, &pnCount);//��ʼ�����뱾
	//readPwd(pPwd, &pnCount);
	printf("��ǰ���������%d\n", pnCount);
	printf("��ǰ������%d\n", g_nNum);
	int flag = 1;
	while (flag) {
		printf("================================================\n");
		printf("1 �鿴ȫ������   2 ��������   3 ɾ������\n");
		printf("4 �޸�����       5 ��ѯ����   6 �����ı�\n");
		printf("7 �޸Ĳ�������   8 �޸�����   9 �˳�\n");
		printf("���������Ĳ���ѡ�\n");
		printf("================================================\n");
		int option;

		scanf_s("%d", &option);
		while ('\n' != getchar());

		switch (option) {
		case �鿴����:
			searchAllPwd(ppPwd, pnCount);
			break;
		case ��������:
			insertPwd(ppPwd, &pnCount);
			break;
		case ɾ������:
			deletePwd(ppPwd, &pnCount);
			break;
		case �޸�����:
			alterPwd(ppPwd, &pnCount);
			break;
		case ��ѯ����:
			searchPwd(ppPwd, pnCount);
			break;
		case �����ı�:
			savePwd(ppPwd, &pnCount);
			break;
		case �޸Ĳ�������:
			modifyPass();
			break;
		case �޸�����:
			alterVolume(ppPwd, &pnCount);
			break;
		case �˳�:
			flag = 0;
			printf("ллʹ��\n");
			break;
		default:
			flag = 0;
			printf("��������Զ��˳���\n");
			break;
		}
	}
}