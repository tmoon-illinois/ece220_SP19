#include <iostream>
using namespace std;
namespace AAA{
    void printStatus(){
        cout<<"AAA"<<endl;
    }
}
namespace BBB{
    void printStatus(){
        cout<<"BBB"<<endl;
    }
}

using namespace AAA;

int main()
{
    printStatus();
    BBB::printStatus();
}
