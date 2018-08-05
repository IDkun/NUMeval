
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
	// int..
	{
	// // p2==0 ,and go in integer way.
	// for(p=p2;p-p1>1;--p,--p){
		// u16 t,t1,t2;
		// t1=*p-'0';
		// t2=*(p-1)-'0';
		// t=t1+10*t2;
		// seq.push_back(t);
	// }
	// if(p-p1>0){
		// seq.push_back(*p-'0'+10*(*(p-1)-'0'));
	// }
	// else{
		// seq.push_back(*p-'0');
	// } //just for long integer
	}
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
	INT i=1;
	if(!_a.ispositive) _out<<'-';
	bool all0=true;
	
	for(itu16 it=_a.seq.begin();it!=_a.seq.end();++it,++i,++i){
		if(*it) all0=false;
		if(i==_a.point){ //odd
			_out<<(*it)/10;
			_out<<'.';
			if(all0 && _a.point==1 &&_a.sigfig%2==1){
				;
			}else{
				_out<<(*it)%10;
			}
			continue;
		}
		if(i==_a.point+1){ //even
			_out<<'.';
		}
		if(*it<10) _out<<'0';
		_out<<*it;
	}
	return _out;
} ;
std::istream& operator >> (std::istream& _in, Num & _a){
	_in>>tmps;
	_a.Build(tmps);
	return _in;
};

























