

#include <cstdlib>
#include <iostream>

using namespace std;


 
//----------------------------------------------------------------  
class Fruit{
	int no;
	double weight;
	char key;
public:
	Fruit() { cout << "Default ctor(Fruit).this is: " << this << endl; }
	virtual ~Fruit() { cout << "Dtor(Fruit).this is:" << this << endl; }
	void print() { }
	virtual void process() { }
};
//----------------------------------------------------------------  
class Apple: public Fruit{
	int size;
	char type;
public:
	Apple() { cout << "Default ctor(Apple).this is " << this << endl; }
	virtual ~Apple() { cout << " Dtor(Apple).this is " << this << endl; }
	void save() { }
	virtual void process() { }
	
	static void* operator new(size_t size);
	static void  operator delete(void* ptr, size_t size);
	
	static void* operator new[](size_t size);
	static void  operator delete[](void* ptr, size_t size) ;
	
};
//----------------------------------------------------------------  
inline
void* Apple::operator new(size_t size) {
	if (Apple* ptr = (Apple*)malloc(size)) {
		cout << "Apple::new(), size:" <<size<< endl;
        cout <<  "return ptr: " << ptr << endl; 
		return ptr;	
	} else {
		throw bad_alloc();
	}
}

inline
void Apple::operator delete(void* ptr, size_t size) {
	cout << "Apple::delete(), ptr:" << ptr << endl;
	cout << "size :" << size << endl;
	free(ptr);
} 

inline
void* Apple::operator new[](size_t size) {
	if (Apple* ptr = (Apple*)malloc(size)) {
		cout << "Apple::new[](), size: " << size << endl; 
		cout<< "return ptr: " << ptr <<endl;
		return ptr;		
	} else {
		throw bad_alloc();
	}
}

inline
void Apple::operator delete[](void* ptr, size_t size)  {
	cout << "Apple::delete[](), ptr:" << ptr  << endl;
	cout << " size : " << size<<endl;
	free(ptr);
}



int main(int argc, char *argv[])
{
    
    cout << "************************* 试构造与析构代码 ******************** " << endl;
    cout << "---------- Fruit *pf = new Fruit() ---------- " << endl;
  	Fruit *pf = new Fruit();
  	cout << "----------- delete pf ----------------------- " << endl;
	  delete pf;
	  cout << "\n"<< endl;
	
	
	  cout << "------------Fruit *pa = new Apple();---------- " << endl;
	  Fruit *pa = new Apple();
	  cout << "------------	delete pa---------------------- " << endl;
	  delete pa;
    cout << "\n"<< endl;
    cout << "\n"<< endl;
    
    
    cout << "************************* 测试重载new delete代码 ***************** " << endl;
    cout << "------------ Fruit *p = new Fruit()---------- " << endl;
    Fruit *p = new Fruit();
   	cout << "------------ delete p------------------------ " << endl;
	  delete p;
	  cout << "\n"<< endl;
	
	
	  cout << "------------ Fruit *p1 = new Apple()---------- " << endl;
	  Fruit *p1 = new Apple();
	  cout << "------------ delete p1------------------------ " << endl;
	  delete p1;
	  cout << "\n"<< endl;
	
    cout << "------------  Apple *p2 = new Apple[5]---------- " << endl;
    Apple *p2 = new Apple[5];
    cout << "------- " << endl;
    cout << "------------ delete [] p2------------------------ " << endl;
	  delete [] p2;
    cout << "\n"<< endl;	
    
     
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
