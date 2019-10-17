#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
constexpr auto pai = 3.14;
int m, y;
int jiafa(int a,int b)//1
{
	int c=a+b;
	return c;
}
int jianfa(int a,int b)//2
{
	int c=a-b;
	return c;
}
double chengfa(int a,int b)//3
{
	double c=a*b;
	return c;
}
double chufa(double a,double b)//4
{
	double c=a/b;
	return c;
}
int qumo(int a,int b)//5
{
	int c=a%b;
	return c;
}
int jishu(int a)//9
{
	int i,b;
	for (i = 1, b = 0; i < a; i++)
		{
			if (i % 2 == 1)
				b += i;
		}
		return b;
}
double yuanmianji(double r)//6
{
	double d=pai*r*r;
	return d;
}
int oushu(int a)//10
{
	int i = 1;
	int b = 0;
	while (i < a)
		{
			if (i % 2 == 0)
				b += i;
				i++;
		}
		return b;
}
int beishu3(int a)//11
{
	int i = 1;
			do
			{
				if (i % 3 == 0)
					cout << i << endl;
				i++;
			} while (i < a);

		return a;
}
void max_min(int a, int b)//16
{
	int c;
	if (a < b)
	{
		c = a;
		a = b;
		b = c;
	}
	m = a;
	y = b;
}
int max(int a, int b)//15
{
	int c;
	c = a > b ? a : b;
	return c;
}
double pi(double d)//19
{
	double a, b, c, n, v1, v2, i;
	b = 0.00000000000001;
	a = pow(100, d-8);
	v1 = -1000;
	v2 = 0;
	for (i = 0;; i++)
	{
		if (v1 >= v2 && v2 > 0)
			break;
		if (v1 < 0 || v2 < 0 || v1 < v2)
			i++;
		c = v1;
		v1 = ((a - b)*v1 + 2 * b* v2) / (a + b);
		v2 = ((b - a)*v2 + 2 * a* c) / (a + b);
		if (v1 >= v2 && v2 > 0)
			break;
		if (v2 < 0)
		{
			v2 = -1 * v2;
		}
	}
	for (; i > 10;)
	{
		i /= 10.0;
	}
	return i;
}
void jia(int a)//20
{
	int i,b,c,m;
	for(i=1;i<(a+1)/2;i++)
	{
		for(b=0,c=i;;c++)
		{
			b+=c;
			if(b>=a)
			{
				break;
			}
		}
		if(b==a)
		{
			cout<<a<<"=";
			for(m=i;m<c;m++)
			{
				cout<<m<<"+";
			}
			cout<<c<<endl;
		}
	}
}
int main()
{
	int x;



	while (1)
	{
		cout << "***************************************************" << endl;
		cout << "*              小小计算器                         *" << endl;
		cout << "*              1 加法                             *" << endl;
		cout << "*              2 减法                             *" << endl;
		cout << "*              3 乘法                             *" << endl;
		cout << "*              4 除法                             *" << endl;
		cout << "*              5 取模运算                         *" << endl;
		cout << "*              6 计算圆面积                       *" << endl;
		cout << "*              7 判断闰年                         *" << endl;
		cout << "*              8 成绩转换                         *" << endl;
		cout << "*              9 计算从一到输入数之间的奇数和     *" << endl;
		cout << "*              10 计算从1到输入数之间的偶数之和   *" << endl;
		cout << "*              11 输出从1到输入数之间的三的倍数   *" << endl;
		cout << "*              12 求即被3整除又被五整除的数       *" << endl;
		cout << "*              13 求水仙花数                      *" << endl;
		cout << "*              14 判断位数                        *" << endl;
		cout << "*              15 计算最大值                      *" << endl;
		cout << "*              16 计算最大值与最小值              *" << endl;
		cout << "*              17 求最大公约数及最小公倍数        *" << endl;
		cout << "*              18 计算素数                        *" << endl;
		cout << "*              19 计算pi的值                      *" << endl;
		cout << "*              20 加和方式                        *" << endl;
		cout << "*              21 矩阵转置                        *" << endl;
		cout << "*              22 冒泡排序                        *" << endl;
		cout << "*              23 对角线和                        *" << endl;
		cout << "*              24 统计单词个数                    *" << endl;
		cout << "*              25 统计学生信息                    *" << endl;
		cout << "*              26 退出                            *" << endl;
		cout << "***************************************************" << endl;
		cout << "请选择一个功能" << endl;
		cin >> x;
		if (x == 1)
		{
			int a, b;
			cout << "请输入两个数" << endl;
			cin >> a >> b;
			printf("加法结果的十进制是：%d\n", jiafa(a,b));
			printf("加法结果的八进制是：%o\n", jiafa(a,b));
			printf("加法结果的十六进制是：%x\n", jiafa(a,b));
		}
		else if (x == 2)
		{
			int a, b;
			cout << "请输入两个数" << endl;
			cin >> a >> b;
			printf("减法结果的十进制是：%d\n", jianfa(a,b));
			printf("减法结果的八进制是：%o\n", jianfa(a,b));
			printf("减法结果的十六进制是：%x\n", jianfa(a,b));
		}
		else if (x == 3)
		{
			double a, b;
			cout << "请输入两个数" << endl;
			cin >> a >> b;
			printf("乘法结果的小数形式是：%.6f\n", a * b);
			printf("乘法运算的指数形式是：%e\n", a * b);
		}
		else if (x == 4)
		{
			double a, b;
			cout << "请输入两个数" << endl;
			cin >> a >> b;
			if (b == 0)
			{
				printf("输入的被除数为0 无法计算\n");
			}
			else
			{
				printf("除法结果的小数形式是：%.6f", chufa(a,b));
				printf("除法运算的指数形式是：%e", chufa(a,b));
			}
		}
		else if (x == 5)
		{
			int a, b;
			cout << "请输入两个数" << endl;
			cin >> a >> b;
			printf("取模运算结果的十进制是：%d\n", qumo(a,b));
			printf("取模运算结果的八进制是：%o\n", qumo(a,b));
			printf("取模运算结果的十六进制是：%x\n", qumo(a,b));
		}
		else if (x == 6)
		{
			double r;
			cout << "请输入圆的半径" << endl;
			cin >> r;
			if (r <= 0)
			{
				printf("半径应大于0\n");
			}
			else
			{
				printf("该圆的面积是：%.6f\n", yuanmianji(r));
				printf("该圆的面积保留两位小数结果是：%.2f\n", yuanmianji(r));
			}
		}
		else if (x == 7)
		{
			int a;
			cout << "请输入年份" << endl;
			cin >> a;
			if (a < 0)
			{
				printf("数据不合法\n");
			}
			else if (a % 100 == 0)
			{
				if (a % 400 == 0)
				{
					printf("输入的年份是闰年\n");
				}
				else
				{
					printf("输入的年份不是闰年\n");
				}
			}
			else
			{
				if (a % 4 == 0)
				{
					cout << "输入的年份为闰年" << endl;
				}
				else
				{
					cout << "输入的年份不是闰年" << endl;
				}
			}
		}
		else if (x == 8)
		{
			int a;
			cout << "请输入成绩" << endl;
			cin >> a;
			if (a > 100 || a < 0)
			{
				printf("输入错误");
			}
			else if (a >= 90 && a <= 100)
				cout << "优秀" << endl;
			else if (a >= 80)
				cout << "良" << endl;
			else if (a >= 70)
				cout << "中" << endl;
			else if (a >= 60)
				cout << "及格" << endl;
			else
				cout << "不及格" << endl;
		}
		else if (x == 9)
		{
			int a;
			cout << "请输入一个数" << endl;
			cin >> a;

			cout << jishu(a) <<endl;
		}
		else if (x == 10)
		{
			int a, b, i;
			cout << "请输入一个数" << endl;
			cin >> a;

			cout << oushu(a) << endl;
		}
		else if (x == 11)
		{
			int a, i;
			cout << "请输入一个数" << endl;
			cin >> a;
			cout <<beishu3(a)<<endl;
	}
		else if (x == 12)
		{
			int a, b, i;
			cout << "请输入两个数" << endl;
			cin >> a >> b;
			for (i = a; i < b; i++)
			{
				if ((i % 3 == 0) && (i % 5 == 0))
				{
					cout << i << endl;
					break;
				}
			}
		}
		else if (x == 13)
		{
			int a, b, c, d;
			cout << "请输入一个3位数" << endl;
			cin >> d;
			for (int i = 100; i < d; i++)
			{
				a = i / 100;
				b = i / 10 % 10;
				c = i % 10;
				if (a*a*a + b * b*b + c * c*c == i)
					cout << i << endl;
			}
		}
		else if (x == 14)
		{
			int a ;
			cout << "请输入一个数" << endl;
			cin >> a;
			if (a < 0)
				printf("要求输入的数为整数\n");
			else if (a >= 1000)
				printf("要求输入的数为1000以内整数\n");
			else if (a < 10)
				printf("输入的数为1位数，个位是%d\n", a);
			else if (a > 100)
				printf("输入的数是三位数，百位是%d，十位是%d，个位是%d\n", a / 100, a / 10 % 10, a % 10);
			else
				printf("输入的数是2位数，十位是%d，个位是%d\n", a / 10, a % 10);

		}
		else if (x == 15)
		{

			int e, f;
			cin >> e >> f;
			cout << "最大值为:" << max(e, f) << endl;
		}
		else if (x == 16)
			{
			int a, b;
			cin >> a >> b;
			max_min(a, b);
			cout << "最大值为：" << m << endl;
			cout << "最小值为：" << y << endl;
			}
		else if(x == 17)
		{
			int x,y,a,b;

			cout<<"请输入两个数："<<endl;
			cin>>x>>y;
			b = x * y;
			while(a)
			{
			a = x%y;
			x = y;
			y = a;
			}
			cout<<"最小公倍数为："<<x<<endl;
			cout<<"最小公倍数为："<<b/a<<endl;
		}
		else if(x == 18)
		{
			int x,i;
			cin>>x;
			for(i=2;i<x/2;i++)
			{
				if(x%i==0)
				{
					break;
				}
			}
			if (i==x/2)
			{
				cout<<"这个数是素数"<<endl;
			}
			else
			{
			cout<<"这个数不是素数"<<endl;
		 }
	}
		else if(x==19)
		{
			cout<<"请输入需要的pi的位数（小于15）:";
			int a;
			cin>>a;
			printf("pi的值为：%.15f\n",pi(a));
		}
		else if(x==20)
		{
			int a;
			cout<<"请输入一个数字:";
			cin>>a;
			cout<<"所有的加和方式有:"<<endl;
			jia(a);
		}
		else if (x == 21)
		{
		int arr[3][4] = { 1,2,3,4,5,6,7,8,9,1,2,3 }, zhuan[4][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << arr[i][j]<<" ";
			}
			cout << endl;
			}
		cout << endl;
		cout << "转置结果为:";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				zhuan[j][i] = arr[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << zhuan[i][j]<<" ";
			}
			cout << endl;
		}
				}
		else if (x == 22)
		{
		int arr[10];
		cout << "请输入十个数字:";
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}
		int ch;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 10 - i - 1; j++)
			{
				if (arr[j+1] < arr[j])
				{
					ch = arr[j];
					arr[j] = arr[j + 1];
					arr[j+1] = ch;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		}
		else if (x == 23)
		{
		cout << "请输入一个三阶行列式:" ;
		int arr[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> arr[i][j];
			}
		}
		int a=0;
		for (int i=0; i < 3; i++)
		{
			a += arr[i][i];
		}
		cout << "对角线加和为" << a << endl;
		 }
		else if (x == 24)
		{
		int a = 0;
		cout << "请输入一段话:";
		char arr[50] = {'\0'};
		gets(arr);
		for (int i = 0; arr[i]; i++)
		{
			if (arr[i] == ' ')
				a++;
			//for (; arr[i + 1] == ' ';)
			//{
			//	i++;
			//}
		}
		cout << "单词的个数为" << a+1 << endl;
		}
		else if (x == 16)
		{
		int grade = 0;
		struct student
			{
				int xuehao;
				char xingming[10];
				int souce;
			}stu[10],temp;
			for (int i = 0; i < 10; i++)
			{
				cin >> stu[i].xuehao >> stu[i].xingming >> stu[i].souce;
			}
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9 - i; j++)
				{
					if (stu[j].souce > stu[j + 1].souce)
					{
						temp = stu[j];
						stu[j] = stu[j + 1];
						stu[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < 10; i++)
			{
				grade += stu[i].souce;
			}
			for (int i = 0; i < 10; i++)
			{
				cout << stu[i].xuehao << stu[i].xingming << stu[i].souce << endl;
			}
			cout << grade << endl;
		}
		else if (x == 25)
		{
			break;
		}
		else
		{
			cout << "对不起，计算器没有该功能" << endl;
		}
		system("pause");
		system("cls");
	}
		return 0;
}
