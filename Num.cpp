
//introduction


//header
#include "Num.h"
#include <cstdio>
#include <cstring>
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
	Build(s);
};
void Num::Build(char *s){
	// if(!*s) Clear();
	if(*s=='-') ispositive=false;
	char *p1=s,*p2=s;
	p2=s+strlen(s)-1;
	char *p=0;
	for(p=p2;p-p1>1;--p,--p){
		u16 t=atoi(p)+10*atoi(p-1);
		seq.push_back(t);
	}
	if(p-p1>0){
		seq.push_back(atoi(p)+10*atoi(p-1));
	}
	else{
		seq.push_back(atoi(p));
	}
	
	std::reverse(seq.begin(),seq.end());
	prear=seq.end();
};


Num::~Num(){};


// Num Num::operator + (Num const& _a, Num const& _b);
// Num Num::operator - (Num const& _a, Num const& _b);
// Num Num::operator * (Num const& _a, Num const& _b);
// Num Num::operator / (Num const& _a, Num const& _b);
std::ostream& operator << (std::ostream &_out, Num const &_a){
	for(itu16 it=_a.seq.begin();it!=_a.seq.end();++it){
		_out<<*it;
	}
	return _out;
} ;
std::istream& operator >> (std::istream& _in, Num & _a){
	_in>>tmps;
	_a.Build(tmps);
	return _in;
};

























