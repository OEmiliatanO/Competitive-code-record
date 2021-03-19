#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
bool is3mul(const string &number){
  int sum = 0;
  for( int i = 0 ; i < number.length() ; ++i ){
    sum += number[i] - '0';
  }

  return sum % 3 == 0;
}
bool is5mul(const string &number){
  return (number[number.length()-1] - '0') % 5 == 0;
}
bool is11mul(const string &number){
  int sum[2] = {0};
  for( int i = 0 ; i < number.length() ; ++i ){
    sum[i%2] += number[i] - '0';
  }

  return (int)abs( sum[0] - sum[1] ) % 11 == 0;
}
int main(){
  string year;
  bool space = false;
  while( cin >> year ){

    if( space ) {
      printf("\n");
    }
    space = true;

    bool isLeap = false;
    bool hasPrinted = false;
    int lastFourDigit;
    sscanf( year.c_str()+year.length()-4, "%d", &lastFourDigit );
    if( (lastFourDigit % 400 == 0) ||
        (lastFourDigit % 100 != 0 && lastFourDigit % 4 == 0) ){
      printf("This is leap year.\n");
      isLeap = true;
      hasPrinted = true;
    }

    if( is3mul(year) && is5mul(year) ){
      printf("This is huluculu festival year.\n");
      hasPrinted = true;
    }

    if( isLeap && is5mul(year) && is11mul(year) ){
      printf("This is bulukulu festival year.\n");
      hasPrinted = true;
    }

    if( !hasPrinted ){
      printf("This is an ordinary year.\n");
    }
  }
  return 0;
}
