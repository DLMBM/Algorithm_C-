

#include <iostream>
using namespace std;


/*递归思想，分！*/
/*递归求和*/
int sum(int n) {
    if (n == 0)
    {
        return n;
    }
    else
    {
        return sum(n - 1) + n;
    }
}
/*递归法求数组最大值*/
int findMax(int left, int right,int array[]) {

    if (left == right) {
        return array[left];
    }
    
    int a = array[left];
    int b = findMax(left + 1, right, array);

    if (a > b)
    {
        return a;
    }
    else {
        return b;
    }
}

//int sum(int* a) {
//
//    int size = 6;
//    
//    if (size == 0) {
//        return size;
//    }
//    else {
//        return sum(size-1) + a[size];
//    }
//
//}

int main()
{
    //int result=0;
    //int a[6] = {0,1,2,3,4,6};
    //
    //for (int i = 0; i <(sizeof(a)/4); i++)
    //{
    //    result =result + a[i];//累加
    //    
    //}
    //cout << result;

    int a[6] = { 0,1,2,3,4,5 };
    cout << findMax(0,5,a);
}
