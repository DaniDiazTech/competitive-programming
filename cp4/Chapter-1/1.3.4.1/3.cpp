#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int main(){
  int d, m, y; // assumming format: dd/mm/YYYY and AD
  char sep;
  cin >> d >> sep >> m >> sep >> y;
  // Could build manually (Large && piece of code)
  //IN C++ 20:
  year_month_day input_date{year{y}, month{m}, day{d}};
  sys_days input_days  = sys_days{input_date};

  auto today_tp = floor<days>(system_clock::now());
  year_month_day today{today_tp};

  weekday wd{input_days};

  days elapsed = today_tp  - input_days;

  string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  cout << "IN: " << d << "/" << m << "/" << y << endl;
  cout << "CUR: " << today.day() << "/" << today.month() << "/" << today.year() << endl;
  cout << "Day: " << weekdays[wd.c_encoding()] << endl;
  cout << "Elapsed: " << elapsed.count() << endl;
}