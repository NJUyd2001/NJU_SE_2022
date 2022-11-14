#pragma once
#include<iostream>
#include <sys/types.h>
#include<dirent.h>
#include<string.h>
#include"judge_equal.h"
using namespace std;
#include<vector>
class run_OJ
{   
    vector<string> files;
    vector<int> run_results;
    public:
        void getfiles(string path);
        void gen_output_txt(string path);
        void gen_out_file();
        void clear_run_res();
        int get_run_results(int i){return run_results[i];}
        int get_files_num(){return files.size();}
        string get_files(int i){return files[i];}
};