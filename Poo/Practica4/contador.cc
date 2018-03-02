#include <list>
#include "contador.h"

using namespace std;

Contador::Contador(int min,int max,int counter){
	min_=min;
	max_=max;

	if((max>min)&&(counter<=max)&&(counter>=min))counter_=counter;
	else counter_=0;

}

Contador Contador::operator=(const Contador &o){
	if((o.counter_<=max_)&&(o.counter_>=min_)){
		counter_=o.counter_;
		save(counter_);
	}
	return *this; //retorna el objeto que la ha invocado
}

Contador Contador::operator=(const int &o){
	
	if((o<=max_)&&(o>=min_)) counter_=o;
	else{
		if(o>max_) counter_=min_;
		else counter_=min_;
	}
	
	save(counter_);
	
	return *this;
}

Contador Contador::operator++(void){

	if(counter_<max_){
		counter_++;
		save(counter_);
	}

	return *this;

}

Contador Contador::operator++(int){

	Contador o=*this;

	if(counter_<max_){
		counter_++;
		save(counter_);
	}
		return o;

}

Contador Contador::operator--(void){

	if(counter_>min_){
		counter_--;
		save(counter_);
	}

	return *this;

}

Contador Contador::operator--(int){

	Contador o=*this;

	if(counter_>min_){
		counter_--;
		save(counter_);
	}
		return o;
		
}

Contador operator+(const int &n, const Contador &o){
	Contador c;
	if((o.counter_+n)<=o.max_) c.counter_=o.counter_+n;
	else c.counter_=o.max_;
	c.save(c.counter_);
	return c;
}

Contador operator+(const Contador &o,const int &n){
	Contador c;
	if((o.counter_+n)<=o.max_) c.counter_=o.counter_+n;
	else c.counter_=o.max_;
	c.save(c.counter_);
	return c;
}

Contador operator-(const int &n, const Contador &o){
	Contador c;
	if((n-o.counter_)>=o.min_) c.counter_=n-o.counter_;
	else c.counter_=o.min_;
	c.save(c.counter_);
	return c;
}

Contador operator-(const Contador &o, const int &n){
	Contador c;
	if((o.counter_-n)>=o.min_) c.counter_=o.counter_-n;
	else c.counter_=o.min_;
	c.save(c.counter_);
	return c;
}

bool Contador::undo(int e){
	int c;
	c=i_.size();
	if ((c<e)||(e<0)) return false;
	list <int>::iterator d,j;
	d=i_.begin();
		for(int i=0;i<e;i++){
			j=d;
			d++;
			i_.erase(j);
	}

	counter_=*d;

	return true;
}