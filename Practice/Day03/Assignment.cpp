#include <iostream>

using namespace std;

static const float MAX_SOCRE = 100.0f;
static const int NUM_OF_SUBJECT = 3;

int main()
{
	float korean{}, eng{}, math{};
	float result{};

	cout << " -- ������ �Է� -- " << endl;
	do{
		cout << "�������� �Է�: ";
		cin >> korean;

		cout << "�������� �Է�: ";
		cin >> eng;

		cout << "�������� �Է�: ";
		cin >> math;

	} while (korean > MAX_SOCRE || eng > MAX_SOCRE || math > MAX_SOCRE);

	result = korean + eng + math;

	cout << " -- ��� ��� -- " << endl;
	cout << "��������: " << korean << endl;
	cout << "��������: " << eng << endl;
	cout << "��������: " << math << endl;
	cout << "����: " << result << endl;
	cout << "���: " << (result / static_cast<float>(NUM_OF_SUBJECT)) << endl;
}