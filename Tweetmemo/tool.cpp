#include <iostream>
#include <Windows.h>
#include "define.h"
void readMemo(char* nowuser) {
	char filename[CHARBUFF];
	char memo[CHARBUFF];
	FILE* fp;

	sprintf_s(filename, "%s.txt", nowuser);
	errno_t error;
	error = fopen_s(&fp, filename, "r");


	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		while (fgets(memo, CHARBUFF, fp) != NULL) {
			fprintf_s(stdout, "%s", memo);
		}
		fclose(fp);
	}
}
void writeMemo(char nowuser[CHARBUFF],char* tempmemo) {
	char filename[CHARBUFF];
	FILE* fp;

	sprintf_s(filename, "%s.txt", nowuser);
	errno_t error;
	error = fopen_s(&fp, filename, "a");

	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		fputs(tempmemo, fp);
		fputs("\n\n", fp);
		fclose(fp);
	}
}



void getGurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}