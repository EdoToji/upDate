#ifndef UPDATE_H
#define UPDATE_H
#include<iostream>
#include<string>
using namespace std;

class upDate{
    private:
        int *p;
        static int dateCount; 

    public:
        //int Greg2Julian(int m, int d, int y);
        //void Julian2Greg(int JD, int &m, int &d, int &y);
        upDate();
        upDate(int M, int D, int Y);
        upDate(int J);
        ~upDate();
        upDate(upDate const &D);
        int julian();
        void setDate(int M, int D, int Y);
        int static GetDateCount();
        int getMonth();
        int getDay();
        int getYear();
        string getMonthName();
        upDate operator=(upDate D);
        upDate operator+(int N);
        friend upDate operator+(int i, upDate D);
        upDate operator+=(int N);
        upDate operator-(int N);
        upDate operator-(upDate D);
        upDate operator-=(int N);
        friend ostream& operator<<(ostream& os, const upDate &D);
        upDate operator++(int N);//postfix ++
        upDate operator++();//prefix ++
        upDate operator--(int N);//postfix --
        upDate operator--();//prefix --

        bool operator==(upDate D);
        bool operator<(upDate D);
        bool operator>(upDate D);
};
#endif
