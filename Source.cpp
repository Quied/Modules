#include <thread>
// #include <iostream>
#include <mutex>
#include <atomic>

import Module;

#define TEMP template <template <typename, typename>>

template <class D, class T>
struct Curriosly : public D, public T{

};

class Derive {
public:
	int data = 42;

};;


class DeriveT {
public:
	int _data = 42;

};;

int main() {
	
	Curriosly<Derive, DeriveT> &a = *(new Curriosly<Derive, DeriveT>);

	delete& a;

	MyFunc();

}