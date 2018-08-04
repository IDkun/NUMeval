#ifndef NUM_H
#define NUM_H

//header
#include <string>
#include <iostream>
#include <vector>


#ifdef __cplusplus
extern "C" {
#endif

//macro
#define MAX_LEN 0x10000 //65536bit 2KB
typedef int INT;
typedef unsigned int u16;

//class

class Num{
private:
	std::vector<u16> seq;/*科学记数法中的数值*/
	INT power /*科学记数法中的位数*/,
		sigfig /*有效数字的位数,also length*/;
	bool ispositive; /*for positive*/
	//u16 * prear;/*最后一位有效数字所在的地址,length-1*/
	
public:
	static std::vector<u16> tmpseq;
	Num();
	Num(short);
	Num(int);
	Num(float);
	Num(double);
	Num(char *s);
	
	~Num();
	
	
	friend Num operator + (Num const& _a, Num const& _b);
	friend Num operator - (Num const& _a, Num const& _b);
	friend Num operator * (Num const& _a, Num const& _b);
	friend Num operator / (Num const& _a, Num const& _b);
	friend std::ostream operator << (std::ostream& _out, Num const& _a);
	friend std::istream operator >> (std::istream& _in, Num const& _a);
	
	
};













#ifdef __cplusplus
}
#endif

//declarations
#ifndef ALLOC_NUM
#define ALLOC_NUM
std::vector<u16> tmpseq;
#endif //ALLOC_NUM
#endif //NUM_H