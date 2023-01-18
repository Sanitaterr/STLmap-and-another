#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<bits/stdc++.h>
#define SALE_DEPATMENT 1
#define DEVELOP_DEPATMENT 2
#define FINACIAL_DEPATMENT 3

using namespace std;
const int maxn = (1 << 20) + 10;

class Person
{
    friend void printMapAll(map<int, Person>& m);
    friend void t1();
public:
    Person() {}
    Person(int num, string name, double score) {
        this->num = num;
        this->name = name;
        this->score = score;
    }

private:
    int num;
    string name;
    double score;
};

void printMapAll(map<int, Person>& m)
{
    map<int, Person>::iterator it = m.begin();
    for (; it != m.end(); it++) {
        cout << (*it).first << " " << (*it).second.name << " " << (*it).second.score << endl;
    }
}

void t1()
{
    map<int, Person>m;
    //方式一
    m.insert(pair<int, Person>(103, Person(103, "lucy", 88.8)));

    //方式二
    m.insert(make_pair(101, Person(101, "bob", 88.8)));

    //方式三
    m.insert(map<int, Person>::value_type(102, Person(102, "tom", 66.6)));

    //方式四（危险）
    m[104] = Person(104, "deam", 99.9);

    printMapAll(m);

    cout << m[101].num << " " << m[101].name << " " << m[101].score << endl;
    cout << m[107].num << " " << m[107].name << " " << m[107].score << endl;
    cout << "--------------" << endl;
    printMapAll(m);
}

class Employee
{
    friend void showDepartmentEmpolyee(multimap<int, Employee>& m);
    friend void employeeJoinDepartment(vector<Employee>& v, multimap<int, Employee>& m);
public:
    Employee() {}
    Employee(string name, int age, int money, string tel) {
        this->name = name;
        this->age = age;
        this->money = money;
        this->tel = tel;
    }

private:
    string name;
    int age;
    int money;
    string tel;
};

void createVectorEmployee(vector<Employee>& v)
{
    for (int i = 0; i < 5; i++) {
        string seddName = "ABCDE";
        string tmpName = "员工";
        tmpName += seddName[i];
        int age = 20 + i;
        int money = 15000 + rand() % 10 * 1000;
        string tel = to_string(rand());

        v.push_back(Employee(tmpName, age, money, tel));
    }
}
void employeeJoinDepartment(vector<Employee>& v, multimap<int, Employee>& m)
{
    vector<Employee>::iterator it = v.begin();
    for (; it != v.end(); it++) {
        cout << "请输入[" << (*it).name << "]加入的部门0(销售),1(研发),2(财务):";
        int op = 0;
        cin >> op;
        m.insert(make_pair(op, *it));
    }
}
void showDepartmentEmpolyee(multimap<int, Employee>& m)
{
    cout << "请输入你要显示的部门0(销售),1(研发),2(财务):";
    int op = 0;
    cin >> op;
    switch (op)
    {
    case 0:
        cout << "---------销售部门员工如下---------" << endl;
        break;
    case 1:
        cout << "---------研发部门员工如下---------" << endl;
        break;
    case 2:
        cout << "---------财务部门员工如下---------" << endl;
        break;
    }

    //寻找op的位置
    multimap<int, Employee>::const_iterator ret;
    ret = m.find(op);
    if (ret == m.end()) {
        return;
    }
    //统计op个数
    int count = m.count(op);
    //从op的位置按照个数逐个遍历
    for (int i = 0; i < count; i++, ret++) {
        //*ret==pair<int,Employee>
        cout << "\t" << (*ret).second.name << " " << (*ret).second.age << " " << (*ret).second.money << " " << (*ret).second.tel << endl;
    }

}
void t2()
{
    //创建5名员工
    vector<Employee>v;
    createVectorEmployee(v);
    //5名员工加入部门
    multimap<int, Employee>m;
    employeeJoinDepartment(v, m);
    //显示部门员工
    showDepartmentEmpolyee(m);
}
int main()
{
    //t1();
    t2();
    return 0;
}