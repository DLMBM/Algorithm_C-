#include <iostream>

using namespace std;

void increment_all(int* start, int* stop)
{
    int* current = start;
    while (current != stop) {
        ++(*current);  // increment value pointed
        ++current;     // increment pointer
    }
}

void print_all(const int* start, const int* stop)
{
    const int* current = start;
    while (current != stop) {
        cout << *current << '\n';
        ++current;     // increment pointer
    }
}

//this is a function can increase the value that pointer pointed by one
void increase(void* data, int psize)
{
    if(psize==sizeof(char))
    {
        char* pchar;
        pchar = (char*)data;
        ++(*pchar);
    }
    else if (psize == sizeof(int))
    {
        int* pint;
        pint = (int*)data;
        ++(*pint);
    }
}

int addition(int a, int b)
{
    return (a + b);
}

int subtraction(int a, int b)
{
    return (a - b);
}
//function as a pointer
int operation(int x, int y, int (*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return (g);
}

int main()
{
  /*basic knowledge 
   the declaration of pointers
   the address-of operator &
   the dereference operator *
  */
   /* int var = 5;
    int* foo = &var;
    int bar =*foo;
    cout <<"the vlaue of foo is "<< foo<<"whih is the address of var"<< endl;
    cout<<"the dereference value of foo is"<<*foo<<which is the value pointed to var<<endl;
    cout<<"the address of foo(&foo) is "<<&foo<<endl;
    */

    /*pointer and array discussion
    the address of array 
    some operation of array and pointer
    */

    //int a[3] = { 1,2,3 };
    //cout << "the address of array is &a or a " << a << endl;
    //you can assign the first element's address to a new integer pointer
    //an array can always be implicitly converted to the pointer of the proper type
    //int* arraypointer=a;
    //cout << "we assign the first element's address "<<arraypointer<<" to arraypointer" << endl;
    //you can't assign an address to an array, like that: a=arraypointer;

    /*the operation of array and pointer*/
    //int numbers[5];
    //int* p;
    //p = numbers;
    //*p = 10;//the first element's address is the address of array
    //p++;//increment p
    //*p = 20;
    //p = &numbers[2]; //let p= the address of the third element
    //*p = 30;
    //p = numbers + 3;
    //*p = 40;
    //p = numbers;
    //*(p + 4) = 50;
    //for (int i = 0; i < 5; i++)
    //{
    //   cout << numbers[i] << ",";
    //}
    
    //why we can access the address of the non-first elements of an array using: p=&number[2];
    //but we can't do that to the first element, like &a
    // that is because the name of array "a" is not always represent as the address of the first element,
    // in this case, "a" represents a pointer pointing to an array in the length of this array
    // so when you write int* point =&a; the ERROR0144 occurs,"int(*)[3]"类型的值不能用于初始化“int*”类型的实体
    //the other case is calculate the size of an array, sizeof(a), it returns the length of array instead of the length of a pointer
    
   //int a[3] = { 1,2,3 };
   //int* point = &a;----error0144 
   // it can resolve in this way
   // int(*p)[3] = &a;


    /*pointer arithmetics
    
    "*" operator is at a higher level than "++" operator
     *p++: *(p++)dereference unincremented address,increment pointer
     *++p: *(++p)dereference incremented address,increment pointer
     ++*p: ++(*p)dereference pointer,and increment the value it points to
     (*p)++: dereference pointer,and post-increment the value it points to
    
     the difference between"i++" and "++i"
    ++i return the incremented value, and can be the left value先自增再赋值
    i++ return the unincremented,post-increment value, and can't be the left value先赋值再自增
    */

    /*pointer and string iterals*/
    //this is a method to solve E0144"const char *" 类型的值不能用于初始化 "char *" 类型的实体.
    //this method is in branch of the principle of pointer, the pointer is a type of variable storing the address
    //but, we assign "hello" to the char*. This is just like we assign an integer 5 to an int* than assign an address!!!!!!
    /*
    char* foo = (char*)"hello";
    cout <<"get the first character:"<< *foo<<endl <<"read the value pointer foo stored:"<<foo<< endl;
    */
    /* 'h' 'e' 'l' 'l' 'o' '\0' used six cells */
    //const char* foo = "hello";
    //cout << foo << endl << *foo << endl << &foo << endl;
    //cout << foo[4] << endl << *(foo + 4) << endl;

    /*pointer and const pointer
    int x;
      int *       p1 = &x;  // non-const pointer to non-const int 都可变
const int *       p2 = &x;  // non-const pointer to const int 指向的内容不可变
      int * const p3 = &x;  // const pointer to non-const int 指针指向的地址不可变
const int * const p4 = &x;  // const pointer to const int 都不可变
    */

    //you can read this pointed value but you can't assign it
    //int x;
    //int y = 10;
    //const int* p = &y;//--不可变值的const qualifier
    //x = *p;//--read the const pointer pointed value
    //*p = x;//--error 0137表达式必须是可修改的左值


   /* 
    int numbers[] = { 10,20,30 };
    increment_all(numbers, numbers + 3);
    print_all(numbers, numbers + 3);
    */
    



    /*pointer to pointer*/
    //int x = 6;
    //int* y;// pointer
    //int** z;// second-ordered pointer only implements on pointer


    /*void pointers
    void represents for the absence of type.
    void pointers are pointers that point to a value that has no type
    and thus also an undetermined length and undetermined dereferencing properties
    */
    
    /*code example
    char a = 'x';
    int b = 1602;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    cout << a << "," << b << endl;
    */



    /*Invalid and Null pointers*/
    /*invalid pointer
    uninitialized pointer error: int* p;
    int myarray[10];
    int *q=myarray+20;//element out of bounds
    */
    /*NULL pointers
    NULL pointers are not Void pointers!!!!!!!!!!!!!!
    */
    //int* p = 0;
    //int* q = nullptr;

    /*Pointers to Func
    软件分层设计，回调函数，下层调用上层接口
    写库
    引用不在代码段中的函数
    函数指针与指针数据的结合可以实现典型的表驱动
    */
    /*int m, n;
    int (*minus)(int, int) = subtraction;
    m = operation(7, 5, addition);
    n = operation(20, m, minus);
    cout << n;*/

}


