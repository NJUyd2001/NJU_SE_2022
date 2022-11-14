#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<time.h>
using namespace std;
#include"create_input.h"

int create_input::get_number()
{
    return number;
}
create_input::create_input(string path)
{
    ifstream file_num(path, ios::in);
    string content;
    number = 0;
    if (file_num)
    {
        while (file_num >> content)
        {
            number++;
        }

    }
    file_num.close();
    vector_type = new input_att[number];
    ifstream file(path, ios::in);
    string char_ = "char";
    string str_ = "string";
    string int_ = "int";
    if (file)
    {
        int i = 0;
        while (file >> content)
        {
            if (content.find(str_) != string::npos)
            {
                vector_type[i].type = "string";
                int j = 8;
                int state = 0;
                string start;
                string end;
                for (; j < content.length(); j++)
                {
                    if (content[j] == ',')
                        state = 1;
                    else if (content[j] == ')')
                        continue;
                    else if (state == 0)
                    {
                        start += content[j];
                    }
                    else if (state == 1)
                    {
                        end += content[j];
                    }

                }
                stringstream t;
                t << start;
                t >> vector_type[i].start;
                stringstream d;
                d << end;
                d >> vector_type[i].end;
            }
            else if (content.find(int_) != string::npos)
            {
                vector_type[i].type = "int";
                int j = 4;
                int state = 0;
                string start;
                string end;
                for (; j < content.length(); j++)
                {
                    if (content[j] == ',')
                        state = 1;
                    else if (content[j] == ')')
                        continue;
                    else if (state == 0)
                    {
                        start += content[j];
                    }
                    else if (state == 1)
                    {
                        end += content[j];
                    }

                }
                stringstream t;
                t << start;
                t >> vector_type[i].start;
                stringstream d;
                d << end;
                d >> vector_type[i].end;
            }
            else if (content.find(char_) != string::npos)
            {
                vector_type[i].type = "char";
                vector_type[i].start = 0;
                vector_type[i].end = 0;
            }
            i++;
        }
    }
    file.close();
}
string create_input::gen_random(int i,int random)
{
    int min = vector_type[i].start;
    int max = vector_type[i].end;
    string type = vector_type[i].type;
    string res;
    srand((unsigned int)time(NULL)+random);
    if (type == "char")
    {
        int random_char = rand()%122+65;
        res = random_char;
    }
    else if (type == "int")
    {
        int random_number = rand()%max+min;
        stringstream t;
        t << random_number;
        t >> res;
    }
    else if (type == "string")
    {
        int random_length = rand()%max+min;
        for (int x = 0; x < random_length; x++)
        {
            int random_char = rand()%122+65;
            res += random_char;
        }
    }
    return res;
}