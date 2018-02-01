#include "studentFunctions.c"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char input;
	char currentUser[USERNAME_STRING_LENGTH];
	char currentPass[PASSWORD_STRING_LENGTH];
	char passCheck[PASSWORD_STRING_LENGTH];
	char *savedText = malloc(SIZE_OF_TEXT_INPUT);
	char fileName[50];
	int looping = 1;
	int menuLoop = 1;
	int loggedIn = 0;
	int choice;
	printf("Welcome!\n");
	savedText[0] = '\0';
	while (loggedIn == 0)
	{
		while (looping == 1) {
			printf("Enter 1 to login\nEnter 2 to register an account\n");
			scanf("%c", &input);
			getchar();
			if (input == '1')
			{
				char nameInput[USERNAME_STRING_LENGTH];
				char passInput[PASSWORD_STRING_LENGTH];

				printf("Please enter your username\n");
				scanf("%s", &nameInput);

				printf("Please enter your password\n");
				scanf("%s", &passInput);

				loginUser(nameInput, passInput, &loggedIn);
				if (loggedIn == 1)
				{
					strcpy(currentUser, nameInput);
					strcpy(currentPass, passInput);

					looping = 0;
				}
			}
			else if (input == '2')
			{
				char nameInput[USERNAME_STRING_LENGTH];
				char passInput1[PASSWORD_STRING_LENGTH];
				char passInput2[PASSWORD_STRING_LENGTH];
				int looping_password = 1;

				printf("Please enter a username (max length 20 characters with no spaces inbetween)\n");
				scanf("%s", &nameInput);
				printf("Username: %s\n", nameInput);
				do {
					printf("Please enter a password (max length 20 characters)\n");
					scanf("%s", &passInput1);
					printf("Please confirm your password\n");
					scanf("%s", &passInput2);
					if (*passInput1 == *passInput2)
					{
						printf("Password confirmed\n");
						looping_password = 0;
					}
					else
					{
						printf("The passwords do not match\nEnter your password again\n");
					}
				} while (looping_password == 1);

				getchar();

				registerUser(nameInput, passInput1);
			}
			else
			{
				printf("wrong input\n");
			}
		}

		while (loggedIn == 1) {
			printf("Main Menu\n----------\n\n");
			printf("Enter 1 to write a text\n\n");
			printf("Enter 2 to save your text on a new file\n\n");
			printf("Enter 3 to add your text to an existing file\n\n");
			printf("Enter 4 decrypt a file and read it\n\n");
			printf("Enter 5 to change your password\n\n");
			printf("Enter 6 to logout\n\n");
			printf("Enter 7 to exit the program\n");
			while (menuLoop == 1)
			{
				printf("looped\n");
				scanf("%d", &choice);

				if (choice == 1)
				{
					newText(currentUser, &savedText);
					printf("Text saved! Now choose what you would like to do with it\n");
				}
				else if (choice == 2)
				{
					printf("What should the new files name be?");
					scanf("%s", fileName);
					newTextFile(currentUser, savedText, fileName);
				}
				else if (choice == 3)
				{
					printf("Which file do you want to add the text to?");
					scanf("%s", fileName);
					addText(currentUser, savedText, fileName);


				}
				else if (choice == 4)
				{
					printf("Which file would you like to read from?");
					scanf("%s", fileName);
					readFromFile(currentUser, fileName);

				}
				else if (choice == 5)
				{
					printf("Please confirm your current password");
					scanf("%s", &passCheck);
					if (strcmp(passCheck, currentPass) == 0) {
						//password switch function
					}
					else
					{
						printf("the entered password does not match you old one");
					}

				}
				else if (choice == 6)
				{
					loggedIn = 0;
					looping = 1;
					menuLoop = 0;
				}
				else if (choice == 7)
				{
					exit(1);
				}
				else
				{
					printf("Wrong input, try again\n");
				}
			}
		}
	}
}