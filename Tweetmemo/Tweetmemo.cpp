// Tweetmemo.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "param.h"
#include "define.h"

int main()
{
	char nowuser[NAMELONG];
	char tmpmemo[CHARBUFF];
	int mode = 0;

	//設定ファイルからデフォルトユーザーを取得
	char defaultuser[NAMELONG];
	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
	GetPrivateProfileString("default","user","none",nowuser,NAMELONG,settingFile);


	//設定ファイルで定められたユーザーのまま実行するか
	printf("このユーザーで続行しますか？:%s\n", nowuser);
	printf("続行する場合は1を、変更する場合は2を入力し、Enterを押してください\n");
	while (mode!=1) {
		scanf_s("%d", &mode);
		if (mode == 2) {
			//ユーザー選択
			printf("ユーザー名を入力してください\n");
			scanf_s("%s", nowuser, NAMELONG);
			printf("ユーザー名：%s\n", nowuser);
			mode = 1;
			break;
			
		}
	}
	mode = 0;

	//モード選択
	while (1) {
		printf("書き込みを行う場合は1を、メモを表示する場合は2を入力し、Enterを押してください\n");
		scanf_s("%d", &mode);
		
		if (mode == 1) {
			printf("120字以内でメモを書き込みEnterを押してください\n");
			scanf_s("%s", tmpmemo,CHARBUFF);			
			
			//構造体格納
			User Nowuser;
			User* pNowuser = &Nowuser;
			pNowuser->tweet = nowuser;
			pNowuser->user = nowuser;

			writeMemo((char*)nowuser,(char*)tmpmemo);
			mode = 0;
		}else if (mode == 2) {
			printf("%sのメモを表示します\n",nowuser);
			readMemo((char*)nowuser);
			mode = 0;
		}
	}
}