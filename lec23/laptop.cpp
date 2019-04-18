#include <iostream>
#include <cstring>

using namespace std;
class laptop{
    private:
    int screenSize;
    int RAM;
    int power;
    char *modelName;//dynamic memeory
    public:
    laptop(){
        cout<<"Called default constructor\n";
        screenSize = 0;
        RAM = 0;
        power = 0;
    }
    laptop(char const *_modelName, int _screenSize, int _RAM, int _power){ 
        cout<<"Called parameterized constructor\n";
        modelName = new char[strlen(_modelName)+1];
        strcpy(modelName, _modelName);
        screenSize = _screenSize;
        RAM = _RAM;
        power = _power;
    }
    ~laptop(){
        cout<<"Called destructor(RAM"<<RAM<<")\n";
        delete []modelName;

    }
    void powerON(){ power = 1;}
    void powerOFF(){ power = 0;}
    void printStatus(){
        cout<<"modelName: "<<modelName<<" Screen size: "<<screenSize<<", RAM: "<<RAM<<", Power: "<<power<<"\n";
    }
};
int main(){

    laptop mylaptop("AAA", 12, 8, 0);

    laptop *p;
    p = &mylaptop;

    p->printStatus();


}




