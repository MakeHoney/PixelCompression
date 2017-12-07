#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _member {
	int num;
	int count;
} Member;


char* createCrate() {
	char* newChar = (char*)malloc(1000);

	return newChar;
}

int saveNumber(Member** memberArr, int* arr, int length) {	// ¸â¹ö °³¼ö return
	//memberArr = (Member**)malloc(sizeof(Member*) * 50);
	int count = 0;

	memberArr[count] = (Member*)malloc(sizeof(Member));
	memberArr[count]->num = arr[0];
	memberArr[count]->count = 1;

	for (int i = 0; i < length - 1; i++) {

		if (arr[i] == arr[i + 1]) 
			(memberArr[count]->count)++;
		else {
			memberArr[++count] = (Member*)malloc(sizeof(Member));
			memberArr[count]->num = arr[i + 1];
			memberArr[count]->count = 1;
		}
	}
	return ++count;
}

void Execute(char strArr[][1000], int num, int input) {

	int testArr[1000];

	for (int i = 0; i < input; i++)
		scanf("%d", &testArr[i]);

	Member** memberArray = (Member**)malloc(sizeof(Member*) * 500);

	int count;

	count = saveNumber(memberArray, testArr, input);

	char** crate = (char**)malloc(sizeof(char*) * count);

	for (int i = 0; i < count; i++) {
		crate[i] = createCrate();
		sprintf(crate[i], "(%d,%d)", memberArray[i]->num, memberArray[i]->count);
		if(i == 0)
			sprintf(strArr[num], "(%d,%d)", memberArray[i]->num, memberArray[i]->count);
		else
			strcat(strArr[num], crate[i]);
	}

	for (int i = 0; i < count; i++) {
		free(crate[i]);
		free(memberArray[i]);
	}
	free(crate);
	free(memberArray);

	return;
}


int main() {
	char strArr[50][1000];
	int input, input2;

	scanf("%d %d", &input, &input2);

	for(int i = 0 ; i < input ; i++)
		Execute(strArr, i, input2);

	for (int i = 0; i < input; i++)
		printf("%s\n", strArr[i]);

}