/*#include<iostream>
using namespace std;
template <class datatype>
class seqlist
{
private:
	datatype *data;
	int maxsize; //maxsize 为线性表的最大可能长度
	int last; //last 为线性表中表尾元素的下标
public:
	seqlist() //创建 100 个元素的线性表的构造函数
	{
		maxsize = 100;
		data = new datatype[maxsize];
		last = -1; //last 为-1 表示为空表
	}
	seqlist(int sz) //创建 sz 个元素的线性表的构造函数
	{
		if (sz > 0)
			maxsize = sz;
		else
			maxsize = 100;
		data = new datatype[maxsize];
		last = -1; //last 为-1 表示为空表
	}
	bool isempty() { return last == -1 ? true : false; } //判空表
	bool isfull() { return last == maxsize - 1; } //判表满
	int length() { return last + 1; } //求表长
	bool getdata(int i, datatype &x) //取元素
	{
		i--;
		if (i >= 0 && i <= last)
		{
			x = data[i];
			return true;
		}
		else
		{
			cout << "非法位置读取元素，不能读取！\n";
			return false;
		}
	}
	bool get_prior(int i, datatype &x); //取前驱元素
	bool get_succ(int i, datatype &x); //取后继元素
	bool replace(int i, datatype x) //置换元素
	{
		i--;
		if (i >= 0 && i <= last)
		{
			data[i] = x;
			return true;
		}
		else
		{
			cout << "非法位置修改元素，不能修改！\n";
			return false;
		}
	}
	bool insert_data(int i, datatype x); //插入元素
	bool delete_data(int i); //删除元素
	void print_list(); //显示表中所有元素
	int find_data(datatype x); //查找元素
	void sort(); //排序元素
	~seqlist() //析构函数
	{
		delete[] data;
	}
};
template<class datatype>
bool seqlist<datatype>::insert_data(int i, datatype x) //线性表的元素插入函数
{
	if (isfull()) //判定表满否
	{
		cout << "表已满，不能插入！\n";
		return false;
	}
	if (i >= 1 && i <= last + 2) //判定插入位置 i 的合法性
	{
		int j;
		//第 i 至第 j 个元素循环后移一个存储位置
		for (j = last; j >= i - 1; j--)
			data[j + 1] = data[j];
		data[j + 1] = x; //x 成为线性表中第 i 个元素
		last++; //线性表的长度加 1
		return true;
	}
	else
	{
		cout << "插入位置错误，不能插入！\n";
		return false;
	}
};
template<class datatype>
bool seqlist<datatype>::delete_data(int i) //线性表的删除元素函数
{
	if (isempty()) //判定表空否
	{
		cout << "表已空，不能删除！\n";
		return false;
	}
	if ((i >= 1) && (i <= last + 1)) //判定删除位置 i 的合法性
	{
		//第 i+1 至第 n 个元素循环前移一个存储位置
		for (int j = i - 1; j < last; j++)
			data[j] = data[j + 1];
		last--; //线性表的长度减 1

		return true;
	}
	else
	{
		cout << "删除位置错误，不能删除！\n";
		return false;
	}
};
template<class datatype>
void seqlist<datatype>::print_list() //打印输出线性表中所有元素
{
	datatype x;
	for (int i = 0; i <= last; i++)
	{
		getdata(i + 1, x);
		cout << x << " ";
	}
	cout << endl;
};
/*
int main()
{
	seqlist<int> linear_list0(-10); //建立长度为 100 的空表
	seqlist<int> linear_list1(10); //建立长度为 10 的空表
	//测试从表头插入建立顺序表类
	for (int i = 0; i < 6; i++)
	{
		linear_list1.insert_data(i + 1, (i + 1) * 100);
		linear_list0.insert_data(i + 1, (i + 1) * 1000);
	}
	linear_list0.print_list(); //打印表 0 的结果
	linear_list1.print_list(); //打印表 1 的结果
	//测试插入位置错误调用插入函数
	linear_list1.insert_data(-1, 1000);
	linear_list1.insert_data(9, 1000);
	linear_list1.print_list(); //打印结果
	
	//测试插入位置错误调用插入函数
	linear_list1.insert_data(8, 1000);
	linear_list1.print_list(); //打印结果
	//测试从表尾插入元素
	linear_list1.insert_data(7, 1000);
	linear_list1.print_list(); //打印结果
	//测试从表的中间位置插入元素
	linear_list1.insert_data(3, 250);
	linear_list1.print_list(); //打印结果
	//测试从表的初始位置删除元素
	linear_list1.delete_data(1);
	linear_list1.print_list(); //打印结果

	seqlist<int> linear1();
	system("pause");
	return 0;
}*/