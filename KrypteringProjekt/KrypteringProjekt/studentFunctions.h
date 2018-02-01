#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable:4996)

#define USERNAME_STRING_LENGTH 20
#define PASSWORD_STRING_LENGTH 20
#define SIZE_OF_TEXT_INPUT 200

inline void registerUser(char name[USERNAME_STRING_LENGTH], char pass[PASSWORD_STRING_LENGTH]);
inline void loginUser(char userName[USERNAME_STRING_LENGTH], char passWord[PASSWORD_STRING_LENGTH], int *login);
inline void newText(char userName[USERNAME_STRING_LENGTH], char *fullText[SIZE_OF_TEXT_INPUT]);
inline void newTextFile(char userName[USERNAME_STRING_LENGTH], char *fullText, char *fileName);
inline void addText(char userName[USERNAME_STRING_LENGTH], char *fullText, char *fileName);
inline void readFromFile(char userName[USERNAME_STRING_LENGTH], char *fileName);


struct user
{
	char userName[USERNAME_STRING_LENGTH];
	char passWord[PASSWORD_STRING_LENGTH];
	/*chiffernyckel*/
	int numFiles;
	char fileName[20];
};