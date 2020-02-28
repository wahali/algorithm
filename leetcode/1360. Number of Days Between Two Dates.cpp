#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5;

int days(string date){
	int year =0,mon = 0,day = 0;
	date = " " + date;
	int ans = 0;
	for(int i = 0;i <date.length();++i){
		if(i>=1&&i<=4)year = year*10+(date[i] - '0');
		else if(i>=6&&i<=7)mon = mon * 10 + (date[i] - '0');
		else if(i>=9&&i<=10)day = day * 10 + (date[i] - '0');
	}
	int flag = 0;
	if(((year%4==0)&&year%100!=0)||year%400==0)flag = 1;
	year--;
	ans += 365 * year + (year/4-year/100+year/400);
	int a[13]={31,28,31,30,31,30,31,31,30,31,30,31};
	mon--;
	for(int i = 0;i< mon;++i)ans += a[i];
	if(flag && mon>=2)	ans++;
	ans += day;
	return ans;
}

int daysBetweenDates(string date1, string date2) {
        return abs(days(date1)-days(date2));
}

int main(){
	
	return 0;
}
