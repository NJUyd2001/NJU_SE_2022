#include<iostream>
using namespace std;
#include<fstream>
#include"judge_equal.h"
void judge_equal::pair_andfirst_judge(run_OJ cur)
{   
    for(int i=0;i<cur.get_files_num();i++)
    {      
         if(cur.get_run_results(i)!=0)
            continue;
        else
        {   
             for(int j=i+1;j<cur.get_files_num();j++)
        {
                if(cur.get_run_results(j)!=0)
                    continue;
                else
                {   
                    OJ_pair pair;
                    pair.oj_i=cur.get_files(i);
                    pair.oj_j=cur.get_files(j);
                    fstream filei(pair.oj_i+"_output.txt",ios::in);
                    fstream filej(pair.oj_j+"_output.txt",ios::in);
                    string content_filei="";
                    string content_filej="";
                    string cur_line;
                    if(filei)
                    {
                        while(getline(filei,cur_line))
                        {
                            content_filei+=cur_line;
                        }
                    }
                    if(filej)
                    {
                        while(getline(filej,cur_line))
                        {
                            content_filej+=cur_line;
                        }
                    }
                    //cout<<content_filei<<" "<<content_filej<<endl;
                    if(content_filei==content_filej)
                        pair.is_equal=true;
                    else
                        pair.is_equal=false;
                    pair_array.push_back(pair);
                }
        }
        }
    }



}
void judge_equal::judge()
{
    for(int i=0;i<pair_array.size();i++)
    {
        fstream filei(pair_array[i].oj_i+"_output.txt",ios::in);
        fstream filej(pair_array[i].oj_j+"_output.txt",ios::in);
        string content_filei="";
        string content_filej="";
        string cur_line;
        if(filei)
            {
                while(getline(filei,cur_line))
                {
                    content_filei+=cur_line;
                }
            }
        if(filej)
            {
                while(getline(filej,cur_line))
                {
                    content_filej+=cur_line;
                }
            }
        if(content_filei!=content_filej)
            pair_array[i].is_equal=false;
    }
}
void judge_equal::last_judge(string path)
{
    string euqal=path+"/euqal.csv";
    string ineuqal=path+"/ineuqal.csv";
    fstream euqal_file(euqal,ios::out);
    fstream ineuqal_file(ineuqal,ios::out);
    for(int i=0;i<pair_array.size();i++)
    {
        if(pair_array[i].is_equal==true)
            euqal_file<<pair_array[i].oj_i<<","<<pair_array[i].oj_j<<endl;
        else
            ineuqal_file<<pair_array[i].oj_i<<","<<pair_array[i].oj_j<<endl;
    }
    euqal_file.close();
    ineuqal_file.close();
}