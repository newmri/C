#include <iostream>

using namespace std;

static const float MAX_SOCRE = 100.0f;
static const int NUM_OF_SUBJECT = 3;

// Branch
// if, switch, goto

int main()
{
	//// ##1. switch
	//switch (integer) { // Only can insert integer.
	//case a: // constant
	//	// if integer is the same with a execute this line.
	//	break; // Escape switch line.
	//case b: // constant
	//	// if integer is the same with b execute this line.
	//	break; // Escape switch line.
	//default: // else
	//	break; // Escape switch line.
	//}

	//int sel{};

	//cout << "Select: ";
	//cin >> sel;
	//switch (sel) { // Execute code when confronted break.
	//case 1: cout << "Cola" << endl; break;
	//case 2: cout << "Sprite" << endl; break;
	//default: cout << "Water" << endl; break;
	//}

	// ����4. ����ǥ�� ���� �߰�
	/*cout << "����4. ����ǥ�� ���� �߰�" << endl;

	float korean{}, eng{}, math{};
	float result{}, avg{};

	cout << " -- ������ �Է� -- " << endl;
	do {
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
	avg = (result / static_cast<float>(NUM_OF_SUBJECT));
	cout << "���: " << avg << endl;
	cout << "����: ";*/
	// ��� ���� 90�̻� 100 ���� -> A
	// ��� ���� 80�̻� 90 �̸� -> B
	// ��� ���� 70�̻� 80 �̸� -> C
	// ��� ���� 60�̻� 70 �̸� -> D
	// �� �� F

	/*switch (static_cast<int>(avg) >= 90 && static_cast<int>(avg) <= 100) {
	case true: cout << "A" << endl; break;
	default:
		switch (static_cast<int>(avg) >= 80 && static_cast<int>(avg) < 90) {
		case true: cout << "B" << endl; break;
		default:
			switch (static_cast<int>(avg) >= 70 && static_cast<int>(avg) < 80) {
			case true: cout << "C" << endl; break;
			default:
				switch (static_cast<int>(avg) >= 60 && static_cast<int>(avg) < 70) {
				case true: cout << "D" << endl; break;
				default: cout << "F" << endl; break;
				}
			}
		}
	}*/

	/*switch (static_cast<int>(avg) / 10) {
	case 10:
	case 9: cout << "A" << endl; break;
	case 8: cout << "B" << endl; break;
	case 7: cout << "C" << endl; break;
	case 6: cout << "D" << endl; break;
	default: cout << "F" << endl; break;
	}*/

	// ##2. goto
	// Can branch code whatever u want.
	// Don't abuse!

	//goto C;
	//cout << "A" << endl;
	//B: cout << "B" << endl;
	//C: cout << "C" << endl;




}