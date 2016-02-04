#include <iostream>
#include <cmath>

using namespace std;

class Base{
   public:
   Base(){};
   virtual double evaluate()=0;
};

class Operand: public Base{
   public:
   double evaluate(){
      return number;
   }
   double number;
   Operand(double x){
      number = x;
   }
};

class Composite: public Base{
   public:
   Base* left;
   Base* right;
   virtual double evaluate()=0;
};

class Sqr: public Base{
   public:
   Base* root;
    double evaluate(){
         return sqrt(root->evaluate());
   }
};

class Add: public Composite{
   public:
   double evaluate(){
      return (left->evaluate() + right->evaluate());
   }
   Add(Base* l, Base* r){
      left = l;
      right = r;
   }
};

class Sub: public Composite{
   public:
   double evaluate(){
      return (left->evaluate() - right->evaluate());
   }
   Sub (Base* l, Base* r){
      left = l;
      right = r;
   }
};

class Mult: public Composite{
   public:
   double evaluate(){
   return (left->evaluate() * right->evaluate());
   }
   Mult (Base* l, Base* r){
   left = l;
   right = r;
  }
};

class Div: public Composite{
   public:
   double evaluate(){
      return (left->evaluate() / right->evaluate());
   }
   Div (Base* l, Base* r){
   left = l;
   right = r;
  }
};

classContainer{
   protected:
      Sort* sort_function;
   public:
      /*Constructors*/
      Container():sort_function(NULL){};
      Container(Sort* function):sort_function(function){};
      /*NonVirtualFunctions*/
      void set_sort_function(Sort*sort_function);
      /*PureVirtualFunctions*/
      virtual void add_element(Base* element)=0;
      virtual void print()=0;
      virtual void sort()=0;
      virtual void swap(inti,intj)=0;
      virtual Base* at(inti)=0;
      virtual int size()=0;
};

classSort{
   public:
      /*Constructors*/
      Sort();
      /*PureVirtualFunctions*/
      virtual void sort(Container* container)=0;
};

int main () {
   Operand* o7 = new Operand(7);
   Operand* o4 = new Operand(4);   
   Mult* m74 = new Mult(o7, o4);
   Operand* o3 =  new Operand(3);
   Add* a3m = new Add(o3, m74);
   Operand* o2 = new Operand(2);
   Sub* a2 = new Sub(a3m, o2);
   cout << endl;
   cout << a2->evaluate() << endl;

}
