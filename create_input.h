#pragma once
#include<iostream>
using namespace std;
struct input_att
{
    int start;
    int end;
    string type;
};
class create_input
{
    int number;
    input_att* vector_type;
public:
    create_input(string path);
    string gen_random(int i,int random);
    int get_number();
};