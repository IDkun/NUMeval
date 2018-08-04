
//introduction


//header
#include "Num.h"
#include <cstdio>
#include <algorithm>
#include <assert.h>



//implementations
	char tmps[MAX_LEN];

Num::Num(){
	sigfig=1;
	power=0;
	ispositive=true;
	prear=seq.end();
};
Num::Num(short i):Num(int(i)) {};
Num::Num(int i):Num(){
	if(i<0) ispositive=false;
	seq.push_back(i);
	sigfig=1;
	power=0;
	if(i>>16){
		seq.push_back(i>>16);
		power++;
		sigfig++;
	}
	std::reverse(seq.begin(),seq.end());
	prear=seq.end();
} ;

Num::Num(float d):Num(double(d)) {};
Num::Num(double d){
	// if(d<0) ispositive=false;
	sprintf(tmps,"%llf",d);
	Num(tmps);
};
Num::Num(char *s){
	;
};

Num::~Num(){};


// Num Num::operator + (Num const& _a, Num const& _b);
// Num Num::operator - (Num const& _a, Num const& _b);
// Num Num::operator * (Num const& _a, Num const& _b);
// Num Num::operator / (Num const& _a, Num const& _b);
// std::ostream operator << (std::ostream& _out, Num const& _a){
	// u16 n;
	// for(itu16 it=_a.seq.begin();it!=_a.seq.end();++it){
		// n=(*it);
		// _out<<n;
	// }
	// return _out;
// } ;
// std::istream operator >> (std::istream& _in, Num const& _a);

























