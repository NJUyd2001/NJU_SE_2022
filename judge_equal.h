#pragma once
#include<iostream>
using namespace std;
#include"run_OJ.h"
#include<vector>
class run_OJ;
struct OJ_pair
{
    string oj_i;
    string oj_j;
    bool is_equal;
};
class judge_equal
{
  vector<OJ_pair> pair_array;  
public:
    void pair_andfirst_judge(run_OJ cur);
    void judge();
    void last_judge(string path);
};