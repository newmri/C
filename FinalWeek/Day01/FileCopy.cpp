#include <iostream>

using namespace std;

int main()
{
	char name[255]{}, copy[255]{};
	cout << "����(���ϸ�.Ȯ����) : ";
	cin >> name;
	cout << "���纻(���ϸ�.Ȯ����) : ";
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