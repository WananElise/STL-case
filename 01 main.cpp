#include<iostream>
using namespace std;
#include<deque>
#include<vector>
#include<algorithm>
#include<ctime>

//�������󣺣���ѡ��ABCDE��10����ί�ֱ��ÿһλѡ�ֽ��д�֣�
// ȥ����߷֣�ȥ����ͷ�,ȡƽ���֣�






//����ѡ��
class player
{
public:

	string name;
	int score;

	player(string name, int score)
	{
		this->name = name;
		this->score = score;
	}


};
void createPalyer(vector<player>& v)
{
	string num = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "player";
		name += num[i];

		int score = 0;

		player p (name, score);
		//��������player����ŵ�������
		v.push_back(p);


	}



}

void setScore(vector<player>& v)
{
	for (vector<player>::iterator it = v.begin(); it != v.end(); it++)
	{

		
		//����ί��ķַ���������
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//��������� ���
			
			int score = rand() % 41 + 60;
			d.push_back(score);

		}
	/*	cout << it->name << " " << "�÷�Ϊ��";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";

		}
		cout << endl;*/

		//����
		sort(d.begin(), d.end());

		//ȥ�������ͷ�
		d.pop_back();
		d.pop_front();

		//��ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;

		}
		int avg = sum / d.size();
		//��ƽ���ָ�ֵ��ѡ������
		it->score = avg;

	}



}

void showScore(vector<player>& v)
{
	for (int i = 0; i < 5; i++)
	{
		cout << v[i].name << "  ƽ���֣�" << v[i].score << endl;
	}


}


int main()
{

	srand((unsigned int)time(NULL));


	//1.��������ѡ��
	vector<player>v;

	createPalyer(v);
	////����
	//for (vector<player>::const_iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "������" << it->name << " ������" << it->score << " ";
	//	cout << endl;
	//}

	//2.��ѡ�ִ��

	setScore(v);

	//3.�ó�ƽ����
	showScore(v);

	system("pause");
	return 0;
}