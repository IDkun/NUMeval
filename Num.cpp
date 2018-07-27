
//introduction


//header
#include "Num.h"

#include <assert.h>


//implementations


Num::Num(){
	sigfig=1;
	power=0;
	prear=seq;
	ispositive=true;
};
Num::Num(short i):Num(int(i)) {};
Num::Num(int i):Num(){
	if(i<0) ispositive=false;
	prear=tmpseq,power=0,sigfig=1;
	while(i>1){
		*prear	=	i%2;
		power++,sigfig++,prear++;
		i>>1;
	}
	for(BIT *prev = &tmpseq[power],perar=seq;prev!=tmpseq;prev--,prear++){
		*prear	=	*prev;
	}
	assert (prear==seq+sigfig);
} ;
Num::Num(float d):Num(double(d)) {};
Num::Num(double d):Num(){
	if(d<0) ispositive=false;
};
Num::Num(char *s){
	;
};

Num::~Num(){};


// friend Num Num::operator + (Num const& _a, Num const& _b);
// friend Num Num::operator - (Num const& _a, Num const& _b);
// friend Num Num::operator * (Num const& _a, Num const& _b);
// friend Num Num::operator / (Num const& _a, Num const& _b);
// friend ostream Num::operator << (ostream& _out, Num const& _a);
// friend istream Num::operator >> (istream& _in, Num const& _a);

























