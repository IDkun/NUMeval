


//introduction



//header
#include "Num.h"
#include "Polynomial.h"
#include "ExpNode.h"

//entry



int main(int argc, char *argv[])
{
	Num n("-0.11");
	std::cout<<n<<std::endl;
	n.show_status();
	std::cin>>n;
	std::cout<<n<<std::endl;
	n.show_status();
	return 0;
}





























