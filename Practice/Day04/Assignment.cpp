#include <iostream>

using namespace std;

static const float MAX_SOCRE = 100.0f;
static const int NUM_OF_SUBJECT = 3;

int main()
{
	{
		// ����1. ���� �ϳ��� �Է¹޾Ƽ� �������� ������� �Ǻ�, if�� �̿�, (0�� ���)
		cout << "����1.���� �ϳ��� �Է¹޾Ƽ� �������� ������� �Ǻ�, if�� �̿�, (0�� ���)" << endl;
		int num{};
		cout << "���� �Է�: ";
		cin >> num;
		if (num >= 0) cout << "����Դϴ�" << endl;
		else cout << "�����Դϴ�" << endl;
	}
	{
		// ����2. �� ���� ������ �Է� �޾Ƽ� �μ��� ���� ���� �� ���. (�� ���� ��ġ ��� ����) (if�� �̿�)
		cout << "����2. �� ���� ������ �Է� �޾Ƽ� �μ��� ���� ���� �� ���. (�� ���� ��ġ ��� ����) (if�� �̿�)" << endl;
		int lValue{}, rValue{};
		cout << "1�� ���� �Է�: ";
		cin >> lValue;
		cout << "2�� ���� �Է�: ";
		cin >> rValue;
		cout << "���� ��: ";
		if (lValue > rValue) cout << lValue - rValue << endl;
		else cout << rValue - lValue << endl;
	}
	{
		// ����3. ����2�� ���׿����ڸ� ���� �ذ�
		cout << "����3. ����2�� ���׿����ڸ� ���� �ذ�" << endl;
		int lValue{}, rValue{};
		cout << "1�� ���� �Է�: ";
		cin >> lValue;
		cout << "2�� ���� �Է�: ";
		cin >> rValue;
		cout << "���� ��: ";
		int ret = (lValue > rValue) ? (lValue - rValue) : (rValue - lValue);
		cout << ret << endl;

	}
	{
		// ����4. ����ǥ�� ���� �߰�
		cout << "����4. ����ǥ�� ���� �߰�" << endl;
	
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
		cout << "����: ";
		// ��� ���� 90�̻� 100 ���� -> A
		// ��� ���� 80�̻� 90 �̸� -> B
		// ��� ���� 70�̻� 80 �̸� -> C
		// ��� ���� 60�̻� 70 �̸� -> D
		// �� �� F

		if (avg >= 90.0f && avg <= 100.0f) cout << "A" << endl;
		else if (avg >= 80.0f && avg < 90.0f) cout << "B" << endl;
		else if (avg >= 70.0f && avg < 80.0f) cout << "C" << endl;
		else if (avg >= 60.0f && avg < 70.0f) cout << "D" << endl;
		else cout << "F" << endl;
	}

}