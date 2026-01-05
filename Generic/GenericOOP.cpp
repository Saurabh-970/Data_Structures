//Generic code
#include<iostream>
using namespace std;

//----------------------------------------------------------------------------------------------//
//
//  Required Header Files
//
//----------------------------------------------------------------------------------------------//

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int no);
        ~ArrayX();
        void Accept();
        void Display();
        T Addition();
        T Maximum();
        int Frequency(int);

};

//----------------------------------------------------------------------------------------------//

template <class T>
ArrayX<T> :: ArrayX(int no)
{
    cout<<"Inside Constructor\n";
    iSize = no;
    Arr = new T[iSize];

}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    cout<<"Inside Destructor\n";
    delete [] Arr;
}

//----------------------------------------------------------------------------------------------//

template <class T>
void ArrayX<T> :: Accept()
{
    int iCnt = 0;

    cout<<"Enter the elements :\n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

//----------------------------------------------------------------------------------------------//

template <class T>
void ArrayX<T> :: Display()
{
    int iCnt = 0;
    cout<<"Elements of the Array are :\n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";


}

//----------------------------------------------------------------------------------------------//

template <class T>
T ArrayX<T> :: Addition()
{
    T iSum = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize ; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

//----------------------------------------------------------------------------------------------//

template <class T>
T ArrayX<T> :: Maximum()
{
    T max;
    int iCnt = 0;

    max = Arr[0];
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > max)
        {
            max = Arr[iCnt];
        }
        
    }
    return max;
}

//----------------------------------------------------------------------------------------------//

template <class T>
T ArrayX<T>  :: Frequency(int iNo)
{
    int iCnt  = 0;
    int Count = 0;

    for(iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt]  == iNo)
        {
            Count++;
        }
    }
    return Count;
}

//----------------------------------------------------------------------------------------------//

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements \n";
    cin>>iValue;

    // Step 1 : Allocate the memory
    ArrayX<int> *aboj = new ArrayX<int>(iValue);

    //Step 2 : Use the memory
    aboj->Accept();
    aboj->Display();

    cout<<"Summation of all elements :"<<aboj->Addition()<<"\n";
    cout<<"Maximum of all elements :"<<aboj->Maximum()<<"\n";
    cout<<"Frequency of all elements :"<<aboj->Frequency(11)<<"\n";

    // Step 3 : Deallocate the memory
    delete aboj;
    return 0;
}