#include <iostream>

using namespace std;

int main()
{
	// ##1. File Input and Output
	// When using console input and output, os automatically create and destroy input and output stream
	// However, when using file input and output, need to request creating and destroying stream
	// create stream: fopen_s
	// destroy stream: fclose

	// ##2. File output
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/t1.txt", "w");

	// return 0 when creation is success
	if (err == 0) {
		fputs("Hello world \n", fp);
		fclose(fp);

	}
	else {
		cout << "File open fail" << endl;
		fclose(fp);
	}

	// ##3. File input
	{
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, "../Data/t1.txt", "r");
		if (err == 0) {
			char input[16]{};
			fgets(input, 16, fp);
			//cout << input << endl;
			fclose(fp);

		}
		else fclose(fp);

	}

	{
		// ##4. File Open Mode
		// r: input, if don't exist target file, error!
		// w: output (over write) if don't exist target file, create file!
		// a: output (append write) if don't exist target file, create file!

		// t: text mode, recognizable input output
		// b: binary mode, binary  input output
		// Movie, Image, MP3 and ETC

		// wt: text mode output
		// rb: binary mode input

	}

	{
		// ##5. Dose exist null character during input output?
		FILE* fp = nullptr;
		
		errno_t err = fopen_s(&fp, "../Data/t1.txt", "rt");
		if (err == 0) {
			int ch{};

			while (EOF != ch) {
				putchar(ch);
				ch = fgetc(fp);
			}

			fclose(fp);

		}
		else fclose(fp);
	}

	{
		FILE* fp = nullptr;

		errno_t err = fopen_s(&fp, "../Data/t1.txt", "w");
		if (err == 0) {
			fputs("NAME: KIM HUIBAE \n AGE: 26 \n", fp);
			fclose(fp);

		}
		else fclose(fp);

		err = fopen_s(&fp, "../Data/t1.txt", "r");
		int ch{};
		while (EOF != ch) {
			putchar(ch);
			ch = fgetc(fp);
		}

		fclose(fp);

	}
	system("pause");
}