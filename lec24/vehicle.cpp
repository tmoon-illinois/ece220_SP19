#include <iostream>
using namespace std;

class Vehicle{//abstract class
    protected:
        int passenger;
        double baggage;
    public:
        Vehicle(int person, double weight){
            passenger = person;
            baggage = weight;
        }
        void Ride(int person){
            passenger += person;
        }
        void Load(double weight){
            baggage += weight;
        }
/*        
        virtual void ShowData(){
            cout<<"<<Vehicle>> "<<endl;
            cout<<"passenger: "<<passenger<<endl;
            cout<<"baggage: "<<baggage<<endl;
        }
        */
        virtual void ShowData() = 0;//pure virtual function
};

class Airplane : public Vehicle{
    private:
        int crew_man;
    public:
        Airplane(int person, double weight, int crew) : Vehicle(person, weight)
    {
        crew_man = crew;
    }
        void TakeCrew(int crew){
            crew_man += crew;
        }
        void ShowData(){
            cout<<"<<Airplane>> "<<endl;
            cout<<"passenger: "<<passenger<<endl;
            cout<<"baggage: "<<baggage<<endl;
            cout<<"crew man: "<<crew_man<<endl;
        }
};

class Train : public Vehicle{
    private:
        int length;
    public:
        Train(int person, double weight, int len) : Vehicle(person, weight){
            length = len;
        }
        void AddLength(int len){
            length += len;
        }
        void ShowData(){
            cout<<"<<Train>> "<<endl;
            cout<<"passenger: "<<passenger<<endl;
            cout<<"baggage: "<<baggage<<endl;
            cout<<"length : "<<length<<endl;
        }
};

class City{
    private:
        Vehicle *vlist[100];
        int index;
    public:
        City(){ index = 0;}
        void AddVehicle(Vehicle *v){
            vlist[index++] = v;
        }
        void ShowList(){
            for(int i=0;i<index;i++)
                vlist[i]->ShowData();
        }
};

int main(){
/*
    Airplane a(100,300,20);
    Train t(50,100,30);
    a.ShowData();
    t.ShowData();

    Vehicle *ptr;
    ptr = &a;
    ptr->ShowData();
*/

    City Champaign;

    Champaign.AddVehicle(new Airplane(30,100,5));
    Champaign.AddVehicle(new Train(100,300,10));
    Champaign.AddVehicle(new Train(130,300,15));

    Champaign.ShowList();

    Vehicle v(10,100);//compile error
    Vehicle *vptr;

}

