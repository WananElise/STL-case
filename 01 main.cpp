#include<iostream>
using namespace std;
#include<deque>
#include<vector>
#include<algorithm>
#include<ctime>

//案例需求：：有选手ABCDE，10个评委分别对每一位选手进行打分，
// 去除最高分，去除最低分,取平均分；






//创建选手
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
		//将创建的player对象放到容器中
		v.push_back(p);


	}



}

void setScore(vector<player>& v)
{
	for (vector<player>::iterator it = v.begin(); it != v.end(); it++)
	{

		
		//将评委打的分放入容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//随机数种子 打分
			
			int score = rand() % 41 + 60;
			d.push_back(score);

		}
	/*	cout << it->name << " " << "得分为：";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";

		}
		cout << endl;*/

		//排序
		sort(d.begin(), d.end());

		//去除最高最低分
		d.pop_back();
		d.pop_front();

		//获取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;

		}
		int avg = sum / d.size();
		//将平均分赋值给选手身上
		it->score = avg;

	}



}

void showScore(vector<player>& v)
{
	for (int i = 0; i < 5; i++)
	{
		cout << v[i].name << "  平均分：" << v[i].score << endl;
	}


}


int main()
{

	srand((unsigned int)time(NULL));


	//1.创建五名选手
	vector<player>v;

	createPalyer(v);
	////测试
	//for (vector<player>::const_iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名：" << it->name << " 分数：" << it->score << " ";
	//	cout << endl;
	//}

	//2.给选手打分

	setScore(v);

	//3.得出平均分
	showScore(v);

	system("pause");
	return 0;
}