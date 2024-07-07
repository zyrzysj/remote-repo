#include "pch.h"
#include<iostream>
using namespace std;
double investment(string name, int number, string style, double price) {
	double W = price * number;
	if (style == "JPY") {
		W = W/ 22;
	}
	if (style == "EUR") {
		W = W / 0.13;
	}
	if (style == "USD") {
		W = W / 0.14;
	}
	return W;
}
TEST(testinvestment, CNYwithJPY) {
	double a1=investment("zhangsan",1000,"CNY", 25);
	double a2 = investment("lisi", 2200, "JPY", 100);
	double result = 1000 * 25 + (2200 * 100 )/ 22;
	ASSERT_EQ(result, a1 + a2);

}
TEST(testinvestment, CNYwithEUR) {
	double a1 = investment("zhangsan", 1000, "CNY", 25);
	double a2 = investment("wangwu", 130, "EUR", 70);
	double result = 1000 * 25 + (130 * 70) / 0.13;                
	ASSERT_EQ(result, a1 + a2);

}TEST(testinvestment, CNYwithUSD) {
	double a1 = investment("zhangsan", 1000, "CNY", 25);
	double a2 = investment("lisi", 280, "USD", 120);
	double result = 1000 * 25 + (280 * 120) / 0.14;
	ASSERT_EQ(result, a1 + a2);

}