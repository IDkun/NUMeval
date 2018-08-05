
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
	point=-1;
	power=0;
	ispositive=true;
	prear=seq.end();
};
Num::Num(short i):Num(int(i)) {};
Num::Num(int i):Num(){
	if(i<0) ispositive=false;
	point=-1;
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

void Num::Clear(){
	seq.clear();
	sigfig=1;
	point=-1;
	power=0;
	ispositive=true;
	prear=seq.end();
};
void Num::Build(char *s){
	Clear();
	if(*s=='-') {ispositive=false;++s;}
	char *p1=s,*p2,*p3;
	p3=s+strlen(s)-1;
	p2=strchr(s,'.');
	sigfig=p3-p1+1;
	if(p2){
		point=p2-p1;
		power=point-1;
		sigfig--;
	}else{
		point=-1;
		power=p3-p1;
	}
	char *p=p3;
	
	u16 t1=0,t2=0;
	bool isodd_digit=true;
	
	do{
		if(p==p2){
			--p;
			continue;
		}
		
		if(isodd_digit){
			t1=*p-'0';
		}else{
			t2=*p-'0';
		}
		if(!isodd_digit){
			seq.push_back(t1+10*t2);
			t1=0;t2=0;
		}
		
		if(p!=p1){
		--p;
		isodd_digit=!isodd_digit;
		}
	} while(p!=p1);
	// p==p1 highest digit:
	if(p==p1){
		if(isodd_digit){
			t1=*p-'0';
		}else{
			t2=*p-'0';
		}
		seq.push_back(t1+10*t2);
		t1=0;t2=0;
	}
	
	std::reverse(seq.begin(),seq.end());
	prear=seq.end();
};

void Num::show_status(){
	for(itu16 it=seq.begin();it!=seq.end();++it){
		std::cout<<*it<<'\t';
	}
	std::cout<<" sigfig : "<<sigfig
	<<" point : "<<point
	<<" power : "<<power
	<<" ispositive : "<<ispositive
	<<std::endl;
}

Num::~Num(){};


// Num Num::operator + (Num const& _a, Num const& _b);
// Num Num::operator - (Num const& _a, Num const& _b);
// Num Num::operator * (Num const& _a, Num const& _b);
// Num Num::operator / (Num const& _a, Num const& _b);
std::ostream& operator << (std::ostream &_out, Num const &_a){
	if(!_a.ispositive) _out<<'-';
	itu16 it=_a.seq.begin();
	bool all0=true,beforep=true;
	INT i=1;
	
	// 0.xx or 0.xxx at front 
	if(_a.seq.front()==0) {
		_out<<'0';
		i=2;
		++it;
		assert(_a.point==1);
		_out<<'.';
		if(_a.sigfig%2==0){
			_out<<'0';
			i=3;
		}
		beforep=false;
	}
	else if(_a.sigfig >_a.power && _a.seq.front()<10){
		if(_a.point==1)
		{
			_out<<"0.";beforep=false;
		}
		_out<<_a.seq.front();
		++it;
		i=2;
		all0=false;
	}
	
	// i begin from 1 or , 2 or 3
	for(;it!=_a.seq.end();++it){
		u16 t1,t2;
		
		t1=*it%10;
		t2=*it/10;
		
		//t2
		if(t2) all0=false;
		if(!(beforep && all0)){
			_out<<t2;
		}
		
		if(i==_a.point) {
			_out<<'.';
			beforep=false;
		}
		
		++i;
		//t1
		if(t1) all0=false;
		if(!(beforep && all0)){
			_out<<t1;
		}
		
		
		if(i==_a.point) {
			_out<<'.';
			beforep=false;
		}
		
		++i;
	}
	return _out;
} ;
std::istream& operator >> (std::istream& _in, Num & _a){
	_in>>tmps;
	_a.Build(tmps);
	return _in;
};

























