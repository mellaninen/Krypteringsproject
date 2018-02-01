#include "studentFunctions.h"

void registerUser(char name[USERNAME_STRING_LENGTH], char pass[PASSWORD_STRING_LENGTH]) {
	struct user newUser;
	char line[sizeof(newUser)];
	int userCreated = 0;
	void *voidPointer = malloc(sizeof(newUser));
	strcpy(newUser.userName, name);
	strcpy(newUser.passWord, pass);


	FILE *fp;
	fp = fopen("students.dat", "ab+");
	if (fp == NULL) {
		printf("Could not open file\n");
	}

	/*while (fgets(line, sizeof(newUser), fp) != NULL)
	{
		if (strstr(line,newUser.userName) != NULL)
		{
			printf("That username already exists");
			userCreated = 1;
		}
		fgets(line, sizeof(newUser), fp);
	}*/
	if (userCreated == 0)
	{
		printf("New user registered\n");
		/*fprintf(fp, "%s", newUser.userName);
		fprintf(fp, "\n");
		fprintf(fp, "%s", newUser.passWord);
		fprintf(fp, "\n");*/
		fwrite(&newUser, 1, sizeof(newUser), fp);
		fclose(fp);
		free(voidPointer);
	}

}

inline void loginUser(char userName[USERNAME_STRING_LENGTH], char passWord[PASSWORD_STRING_LENGTH], int *login){
	struct user newUser;

	/*char pointer[USERNAME_STRING_LENGTH];
	char bufferName[sizeof(struct user)];
	char bufferPass[sizeof(struct user)];*/

	int userFound = 0;
	int lenName;
	int lenPass;
	lenName = strlen(userName);
	lenPass = strlen(passWord);
	//strcpy(pointer, userName);

	FILE *fp;
	fp = fopen("students.dat", "ab+");


	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	rewind(fp);


	while (fread(&newUser, sizeof(struct user), 1, fp) != NULL)
	{
		if (strcmp(newUser.userName, userName) == 0) {
			userFound = 1;
			if (strcmp(newUser.passWord, passWord) == 0)
			{
				printf("Login successful\n");
				*login = 1;
			}
			else
			{
				printf("that's the wrong password\n");
			}
		}
	}
	if (userFound == 0) {
		printf("that username does not exist\n");
	}
	
/*	while (fgets(pointer, USERNAME_STRING_LENGTH, fp) != NULL && loggedIn == 0)
	{
		//strtok(pointer, "\n");

		if (*pointer == *userName)
		{
			fgets(pointer, PASSWORD_STRING_LENGTH, fp);
			if (*pointer == *passWord)
			{
				printf("Logged in succesfully!\n");
				loggedIn = 1;
			}
			else
			{
				printf("The password didn't match.\n");
			}
		}
		else
		{
			printf("test");
		}
	}
	*/
}

inline void newText(char userName[USERNAME_STRING_LENGTH], char *fullText[SIZE_OF_TEXT_INPUT]) {
	strcpy(*fullText, "");

	char text[SIZE_OF_TEXT_INPUT];

	printf("when you are done writing, enter ''-1'' on a new line (Please do not enter more than 200 characters on a single line)\n");

	while (strcmp(text, "-1\n") != 0)
	{
		fgets(text, 200, stdin);
		strcat(*fullText,text);
	}

}

inline void newTextFile(char userName[USERNAME_STRING_LENGTH], char *fullText, char *fileName) {
	strcat(fileName, ".txt");
	printf("%s\n", fileName);
	printf("%s\n", fullText);

	FILE *fp;
	fp = fopen(fileName, "w");
	if (!fp) {
		printf("something went wrong\n");
	}
	perror("fopen");

	fprintf(fp, "%s", fullText);
	fclose(fp);
}

inline void addText(char userName[USERNAME_STRING_LENGTH], char *fullText, char *fileName) {
	FILE *fp;
	fp = fopen(fileName, "a+");
	if (!fp) {
		printf("Couldn't find file\n");
	}

	printf(fp, "%s", fullText);
	fclose(fp);
}

inline void readFromFile(char userName[USERNAME_STRING_LENGTH], char *fileName) {
	int c;
	FILE *fp;
	fp = fopen(fileName, "r");
	if (fp) {
		while (c = getc(fp) != EOF);
		{
			printf("%d",c);
		}
	}
	else
	{
		printf("Couldn't find file\n");
	}
}
