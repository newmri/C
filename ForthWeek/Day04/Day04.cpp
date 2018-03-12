#include <iostream>

using namespace std;

int main()
{
	// ##1. iostream
	// stream: virtual stream! one way
	// console(keyboard, monitor) when doing input or output, os create stream and destroy
	// input: outer data goes internal of program
	// output: data of internal goes outer

	// keyboard(input device) >> (input stream) >> program >> (output stream) >> monitor(printer device)

	// standard stream
	// stdin: standard input steam target: keyboard
	// stdout: standard output stream target: monitor

	// ##2. input output buffer
	// for effectiveness

	// ##3. single character output function
	// putchar, fputc
	//putchar('a'); // stdout: standard print stream target: monitor
	//fputc('a', stdout); // can decide stream target: many

	// ##4. single character input function
	// getchar, fgetc
	// read single character from input buffer
	// when have no more data to read, return EOF

	//int ch = getchar(); // stdin target: keyboard
	//putchar(ch);

	//ch = getchar();
	//putchar(ch);

	//ch = getchar();
	//putchar(ch);

	//int ch = fgetc(stdin); // can decide stream target: many
	//putchar(ch);

	// ##5. EOF(End Of File) (-1)
	// reason of using int instead of char
	// 1. char is also number
	// 2. char is depend on system configuration (can be unsigned)
	// otherwise, int always stand signed

	//int ch{};
	//while (true) {
	//	ch = getchar();
	//	// ctrl + z happens EOF
	//	if (EOF == ch) break;

	//	putchar(ch);
	//}

	// ##6. string output function
	// puts, fputs
	//puts("hello world"); // stdout(standard output stream) target: monitor auto word break
	//fputs("Hello World", stdout); // target: many

	// ##7. string input function
	// gets_s, fgets
	char input[16] = "";

	//// get_s(array)
	//gets_s(input); // Read spacing words, but not word break
	//puts(input);

	//gets_s(input, 16);
	//puts(input);

	// fgets(buffer, max count, stream)
	// target: many
	// from input buffer, read data with null accurately as much as max count
	//fgets(input, 16, stdin); // not only spacing words but also word break
	//fputs(input, stdout);

	// ##8. empty input buffer
	//char id[16]{""};
	//char name[16]{""};
	//fgets(id, 8, stdin);

	//while ('\n' != getchar()); // empty input buffer
	//
	//fgets(name, 16, stdin);

	//cout << "----------------------------------" << endl;
	//fputs("SSN: ", stdout);
	//fputs(id, stdout);

	//fputs("name: ", stdout);
	//fputs(name, stdout);
	//system("pause");

}