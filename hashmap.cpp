#include <map>
#include <string>
#include <iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{		
	   //hash 表的插入操作
	   map<int, string> mapStudent;
	   mapStudent.insert(pair<int,string>(1,"student_one"));
	   mapStudent.insert(pair<int,string>(2,"student_two"));
	   mapStudent.insert(pair<int,string>(3,"student_three"));
	   //正向遍历
	   map<int, string>::iterator iter;
	   for(iter = mapStudent.begin(); iter != mapStudent.end();iter++)
		{
				cout<<iter->first<<"   "<<iter->second<<endl;
				}
		cout<<endl;
		int size_1 = mapStudent.size();
		cout<<"size of mapStudent is :"<<size_1<<endl;
		cout<<endl;
	   pair<map<int, string>::iterator, bool> Insert_Pair;
       Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_one"));
       if(Insert_Pair.second == true)
       {
              cout<<"Insert Successfully"<<endl;
       }
       else
       {
              cout<<"Insert Failure"<<endl;
       }
	   cout<<endl;
	   int size_2 = mapStudent.size();
		cout<<"size of mapStudent is :"<<size_2<<endl;
		cout<<endl;
	   Insert_Pair = mapStudent.insert(map<int, string>::value_type (4, "student_four"));
	   if(Insert_Pair.second == true)
       {
              cout<<"Insert Successfully"<<endl;
       }
       else
       {
              cout<<"Insert Failure"<<endl;
       }
	   cout<<endl;
		int size_3 = mapStudent.size();
		cout<<"size of mapStudent is :"<<size_3<<endl;
		cout<<endl;
       mapStudent.insert(map<int, string>::value_type (5, "student_five"));
       mapStudent.insert(map<int, string>::value_type (6, "student_six"));
       for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		{
				cout<<iter->first<<"   "<<iter->second<<endl;
		}
	   cout<<endl;
	   int size_4 = mapStudent.size();
	   cout<<"size of mapStudent is :"<<size_4<<endl;
	   cout<<endl;
	   mapStudent[7] =  "student_seven";
       mapStudent[8] =  "student_eight";
       mapStudent[9] =  "student_nine";
       for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		{
				cout<<iter->first<<"   "<<iter->second<<endl;
		}
		cout<<endl;
		int size_5 = mapStudent.size();
		cout<<"size of mapStudent is :"<<size_5<<endl;
		cout<<endl;
		
		//反向遍历
		map<int, string>::reverse_iterator  riter;
        for(riter = mapStudent.rbegin(); riter != mapStudent.rend(); riter++)
		{
				cout<<riter->first<<"   "<<riter->second<<endl;
		}
		cout<<endl;
		
		//数组遍历
		int nSize = mapStudent.size();
		//by rainfish
        for(int nIndex = 1; nIndex < nSize; nIndex++)
		{
				cout<<nIndex<<"   "<<mapStudent[nIndex]<<endl;
		}
		cout<<endl;
		
		//map的count、find 用法
		
		/*数据查找1：用count函数来判定关键字是否出现，
		其缺点是无法定位数据出现位置,由于map的特性，
		一对一的映射关系，就决定了count函数的返回值只有两个，
		要么是0，要么是1，出现的情况，当然是返回1了
		*/
		mapStudent.insert(map<int, string>::value_type(10,"student_ten"));//mapStudent[10] = "student_ten"
		mapStudent.insert(map<int, string>::value_type(11,"student_eleven"));//mapStudent[11] = "student_eleven"
		map<int,string>::iterator it;
		it = mapStudent.find(0);
		cout<<"student_zero find ? : ";
		if(it == mapStudent.end()){
			cout<<"student_zero not found"<<endl;
		}
		else{
			cout<<it->second<<endl;
		}
		cout<<"student_zero count: ";
		cout<<mapStudent.count(10)<<endl;
		
		cout<<"student_ten find: ";
		it = mapStudent.find(10);
		if(it == mapStudent.end()){
			cout<<"student_ten not found"<<endl;
		}
		else{
			cout<<" "<<it->second<<endl;
		}
		cout<<"student_ten count: ";
		cout<<" "<<mapStudent.count(10)<<endl;
		
		cout<<"after inserting student_ten :"<<endl;
		mapStudent.insert(map<int, string>::value_type(10,"student_ten_1"));
		cout<<"student_ten find : ";
		it = mapStudent.find(10);
		if(it == mapStudent.end()){
			cout<<" "<<"student_ten not found"<<endl;
		}
		else{
			cout<<" "<<it->second<<endl;
		}
		cout<<"student_ten count : ";
		cout<<mapStudent.count(10)<<" "<<endl;
		cout<<endl;
		
		/*数据查找2：用find函数来定位数据出现位置，它返回的一个迭代器，
		当数据出现时，它返回数据所在位置的迭代器，
		如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器
		*/
		map<int, string>::iterator fiter;
        fiter = mapStudent.find(6);
		if(fiter != mapStudent.end())
		{
				cout<<"Find, the value is "<<fiter->second<<endl;
		}
		else
		{
				cout<<"have't Found"<<endl;
		}
		cout<<endl;
		
		return 0;
}
运行后：

1   student_one
2   student_two
3   student_three

size of mapStudent is :3

Insert Failure

size of mapStudent is :3

Insert Successfully

size of mapStudent is :4

1   student_one
2   student_two
3   student_three
4   student_four
5   student_five
6   student_six

size of mapStudent is :6

1   student_one
2   student_two
3   student_three
4   student_four
5   student_five
6   student_six
7   student_seven
8   student_eight
9   student_nine

size of mapStudent is :9

9   student_nine
8   student_eight
7   student_seven
6   student_six
5   student_five
4   student_four
3   student_three
2   student_two
1   student_one

1   student_one
2   student_two
3   student_three
4   student_four
5   student_five
6   student_six
7   student_seven
8   student_eight

student_zero find ? : student_zero not found
student_zero count: 1
student_ten find:  student_ten
student_ten count:  1
after inserting student_ten :
student_ten find :  student_ten
student_ten count : 1 

Find, the value is student_six
