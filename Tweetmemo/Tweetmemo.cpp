// Tweetmemo.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include <iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include<math.h>
#include<String.h>

#include "param.h"
#include "define.h"

int main()
{
	char nowuser[NAMELONG];
	char tmpmemo[CHARBUFF];
	int mode = 0;

	//ユーザー選択
	printf("ユーザー名を入力してください\n");
	scanf_s("%s", nowuser,NAMELONG);
	printf("ユーザー名：%s\n", nowuser);

	//モード選択
	while (1) {
		printf("書き込みを行う場合は1を、メモを表示する場合は2を入力し、Enterを押してください\n");
		scanf_s("%d", &mode);
		
		if (mode == 1) {
			printf("100字以内でメモを書き込みEnterを押してください\n");
			scanf_s("%s", tmpmemo,CHARBUFF);
			writeMemo((char*)nowuser,(char*)tmpmemo);
		}else if (mode == 2) {
			printf("%sのメモを表示します\n",nowuser);
			readMemo((char*)nowuser);
		}
	}
}