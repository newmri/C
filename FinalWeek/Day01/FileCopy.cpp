#include <iostream>

using namespace std;

int main()
{
	char name[255]{}, copy[255]{};
	cout << "원본(파일명.확장자) : ";
	cin >> name;
	cout << "복사본(파일명.확장자) : ";
	cin >> copy;

	FILE* fp = nullptr;
	FILE* fpWrite = nullptr;
	errno_t err = fopen_s(&fp, name, "rb");
	err = fopen_s(&fpWrite, copy, "wb");
	if (err == 0) {
		int ch = fgetc(fp);
			while (ch != EOF) {
				fputc(ch, fpWrite);
				ch = fgetc(fp);
			}
		fclose(fp);
	}

}