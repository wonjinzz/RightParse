#include "Parser.c"

FILE* sourceFile;

void icg_error(int n) {
	printf("icg_error: %d\n", n);
}

int main(int argc, char* argv[]) {
	char fileName[255];
	int error;

	printf("[start of Mini C Compiler]\n"); // open file
	if (argc != 2) {
		icg_error(1);
		exit(1);
	}
	strcpy_s(fileName, argv[1]);
	printf("source file name: %s\n\n", fileName);

	error = fopen_s(&sourceFile, fileName, "r");
	if (error != 0) {
		icg_error(2);
		exit(1);
	}

	printf("[start of Parser]\n"); // generate Parser
	parser(sourceFile);
	printf("\n[End of program execution]\n");

	return 0;
}