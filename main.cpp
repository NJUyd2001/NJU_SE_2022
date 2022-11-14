#include<iostream>
#include<time.h>
using namespace std;
#include"create_input.h"
#include"run_OJ.h"
#include<fstream>
using namespace std;
#include"create_input.h"
void input_solve(string path,int &ran)
{
    string input_file_name=path+"/input.txt";
    ofstream input_file(input_file_name,ios::out);
    path += "/stdin_format.txt";
    create_input cur(path);
    int sum=cur.get_number();
    for (int i = 0; i < sum; i++)
    {     
        string number="0";
        number=cur.gen_random(i,ran);
        if(i==sum-1)
        {
            input_file<<number<<"\n";
            cout<<number<<"\n";
            //cout<<number<<"\n";
        }
        else
        {   
            
            input_file<<number<<" ";
            //cout<<number<<" ";
        }
        ran++;
    }
    input_file.close();
}
int main()
{   while(true)
    {
    srand((unsigned int)time(0));
    int cnt=rand()%10+1;
    int ran=rand();
    string dir;
    cout << "输入要判断的OJ程序文件夹名:";
    cin >> dir;
    string path = "/home/minami/Desktop/input/"+dir;
    run_OJ cur;
    judge_equal judge;
    cout << "随机数对数:"<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        input_solve(path,ran);
        if(i==0)
            {
                cur.getfiles(path);
                cur.gen_out_file();
            }
        cur.gen_output_txt(path);
        if(i==0)
            judge.pair_andfirst_judge(cur);
        else
            judge.judge();
        cur.clear_run_res();
    }
    judge.last_judge(path);
    int choice;
    cout<<"您要继续吗? 1:退出;else:继续判断:";
    cin>>choice;
    if(choice==1)
        return 0;
    }
}