#include <iostream>

using namespace std;

int main()
{
	// ##1. File Instructor
	// Exists file instructor in file stream
	// File Instruction has input output from where
	// at the beginning, 'File Instructor' indicates the first line

	// ##2. File Instructor Function
	// fseek, ftell, feof
	// fseek: Control location of instructor
	// ftell: Get location info of instructor
	// feof: Check if current is EOF

	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/test.txt", "rt");
	if (0 == err) {
		fseek(fp, -3, SEEK_END);
		char ch = fgetc(fp);
		cout << "SEKK_END - 3: " << ch << endl;
		cout << "Current Location of Instructor: " << ftell(fp) << endl;
		ch = fgetc(fp);
		cout << "after update: " << ch << endl;
		cout << "Current Location of Instructor: " << ftell(fp) << endl;
		fseek(fp, 3, SEEK_SET);
		ch = fgetc(fp);
		cout << "SEKK_SET + 3: " << ch << endl;
		cout << "Current Location of Instructor: " << ftell(fp) << endl;
		fseek(fp, 1, SEEK_CUR);
		ch = fgetc(fp);
		cout << "SEKK_CUR + 1: " << ch << endl;
		cout << "Current Location of Instructor: " << ftell(fp) << endl;
		fseek(fp, 0, SEEK_SET);
		ch = fgetc(fp);
		cout << "SEKK_SET + 0: " << ch << endl;
		cout << "Current Location of Instructor: " << ftell(fp) << endl;
		fclose(fp);
	}

	else cout << "File Open Fail" << endl;

	system("pause");
}