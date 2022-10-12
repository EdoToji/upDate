#include "upDate.hpp"

int Greg2Julian (int month, int day, int year){
    int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;     
    return JD;         
}
void Julian2Greg (int JD, int & month, int & day, int & year) {
  
  int L = JD + 68569;
  int N = 4 * L/146097;
  L = L-(146097*N+3)/4;
  int I = 4000*(L+1)/1461001;
  L = L-1461*I/4+31;
  int J = 80*L/2447;
  int K = L-2447*J/80;
  L = J/11;
  J = J+2-12*L;
  I = 100*(N-49)+I+L;
  
  year = I;
  month = J;
  day = K;

}

int upDate::dateCount = 0;

upDate::upDate(){
    p = new int[3]; //returns a new pointer to a new int array of size 3
    p[0] = 5;
    p[1] = 11;
    p[2] = 1959;
    dateCount++;

}
upDate::upDate(int Month, int Day, int Year){//change later 
if (Month > 12 || Month < 0 || Day > 31 || Year < 0 ){
        p = new int [3];
        p[0] = 5;
        p[1] = 11;
        p[2] = 1959;
        dateCount++;
    }
    else{
        if (Month == 2 && Day > 29){
            p = new int [3];
            p[0] = 5;
            p[1] = 11;
            p[2] = 1959;
            dateCount++;

        }
        else if ((Month == 4 || Month == 6 || Month == 9 || Month == 11 ) && Day > 30){
            p = new int [3];
            p[0] = 5;
            p[1] = 11;
            p[2] = 1959;
            dateCount++;

        }
        else{
            p = new int [3];
            p[0] = Month;
            p[1] = Day;
            p[2] = Year;
            dateCount++;
        }
    }

}

upDate::upDate(int J){
    if(J < 0){
      p = new int[3];
      p[0] = 5;
      p[1] = 11;
      p[2] = 1959;
      dateCount++;
    }
    else{
      int Month;
      int Day;
      int Year;
      Julian2Greg(J, Month, Day, Year);
      p = new int[3];
      p[0] = Month;
      p[1] = Day;
      p[2] = Year;
      dateCount++;
    }
    
}
//Deconstructor
upDate::~upDate(){
    delete [] p; 
    dateCount--;
}
//Copy Constructor
upDate::upDate(upDate const &D){
    p = new int[3];
    p[0] = D.p[0];
    p[1] = D.p[1];
    p[2] = D.p[2];
    dateCount++;

}

int upDate::julian(){
    return Greg2Julian(p[0], p[1], p[2]);
}
void upDate::setDate(int Month, int Day, int Year){
    p[0] = Month;
    p[1] = Day;
    p[2] = Year;
}

int upDate::GetDateCount(){
    return dateCount;
}

int upDate::getMonth(){
    return p[0];
}

int upDate::getDay(){
    return p[1];
}

int upDate::getYear(){
    return p[2];
}


string upDate::getMonthName(){
    string Month;
  if(p[0] < 1 || p[0] > 12 || p[1] < 1 || p[1] > 31){
    p[0] = 5;
    p[1] = 11;
    p[2] = 1959;
  }

  if(p[0] == 1){
    Month = "January";
  }
  else if(p[0] == 2){
    Month = "Febuary";
  }
  else if(p[0] == 3){
    Month = "March";
  }
  else if(p[0] == 4){
    Month = "April";
  }
  else if(p[0] == 5){
    Month = "May";
  }
  else if(p[0] == 6){
    Month = "June";
  }
  else if(p[0] == 7){
    Month = "July";
  }
  else if(p[0] == 8){
    Month = "August";
  }
  else if(p[0] == 9){
    Month = "September";
  }
  else if(p[0] == 10){
    Month = "October";
  }
  else if(p[0] == 11){
    Month = "November";
  }
  else{
    Month = "December";
  }
  
  return Month;
}


//Assignment Operator 
upDate upDate::operator =(upDate D){
    this -> p[0] = D.p[0];
    this -> p[1] = D.p[1];
    this -> p[2] = D.p[2];
    *(this -> p) = *(D.p);//come back to this

    return *this;
}

upDate upDate::operator +(int N){
    int month;
    int day;
    int year;

    int JD = julian() + N;
    Julian2Greg(JD, month, day, year);
    upDate date(month, day, year);
    return date;
}

upDate operator +(int N, upDate D){
    int month;
    int day;
    int year;

    int JD = D.julian() + N;
    Julian2Greg(JD, month, day, year);
    upDate date(month, day, year);
    return date;
}

upDate upDate::operator+=(int N){
    int JD = this -> julian() + N;
    
    Julian2Greg(JD, p[0], p[1], p[2]);

    return *this;
}


upDate upDate::operator-(int N){
    int M1, D1, Y1;
    int JD = Greg2Julian(p[0], p[1], p[2]);
    JD -= N;
    Julian2Greg(JD, M1, D1, Y1);
    upDate temp(M1, D1, Y1);
    return temp;
}

upDate upDate::operator-(upDate D){
    int JD1 = Greg2Julian(p[0], p[1], p[2]);
    int JD2 = Greg2Julian(D.p[0], D.p[1], D.p[2]);
    
    //find difference between two julian dates
    int daysBetween = JD1 - JD2;
    
    return daysBetween;
}

upDate upDate::operator-=(int N){
  int M1, D1, Y1;
    int JD = Greg2Julian(p[0], p[1], p[2]);
    JD -= N;
    Julian2Greg(JD, M1, D1, Y1);
    
    p[0] = M1;
    p[1] = D1;
    p[2] = Y1;
    return upDate(p[0], p[1], p[3]);
}

ostream& operator<<(ostream& x, const upDate &D){
  x<< D.p[0]<< "/" << D.p[1] << "/" << D.p[2];
  return x;
}
upDate upDate::operator++(int N){ //postfix ++
  int JD =  this -> julian() + 1;

  Julian2Greg(JD, p[0], p[1], p[2]);
  return *this;
}

upDate upDate::operator++(){ //prefix ++
  int JD =  this -> julian() + 1;

  Julian2Greg(JD, p[0], p[1], p[2]);
  return *this;
}

upDate upDate::operator--(int N){ //postfix --
  int JD =  this -> julian() - 1;

  Julian2Greg(JD, p[0], p[1], p[2]);
  return *this;
}

upDate upDate::operator--(){ //prefix//
  int JD =  this -> julian() - 1;

  Julian2Greg(JD, p[0], p[1], p[2]);
  return *this;
}

bool upDate::operator==(upDate D){
  if(julian() == D.julian()){
    return true;
  }
  else{
    return false;
  }
}

bool upDate::operator<(upDate D){
  if(julian() < D.julian()){
    return true;
  }
  else{
    return false;
  }
}

bool upDate::operator>(upDate D){
  if(julian() > D.julian()){
    return true;
  }
  else{
    return false;
  }
}
