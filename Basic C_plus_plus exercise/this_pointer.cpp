# include <iostream>
using namespace std;
# include <string>

// https://www.youtube.com/watch?v=F1Drzhzpwtc&list=PLA1FTfKBAEX6BdpNaWp2uw-YspHwY7qwW&index=28  //
class class_function
{
private:
    int id;
    string name;
public:

/*     //false way:
    class_function(int id, string name) // here give false value becuase here id indicate local/public id, not private
    { id= id;
    name=name; };
 */
    // 1st right way with this operator
    class_function(int id, string name)   // this-> indicate the private variable;not public or local variable.
    {
        this->id = id; this-> name= name;
    }
    // 2nd right way without this operator
    //class_function(int a, string b): id(a), name(b){ };
    void printvalue();
    void Increase_id()
    { this->id= this->id+1;  cout<< "Increase_id(): "<< this->id<< endl;}
    void Increase_id_final()
    { this->Increase_id();  cout<< "Increase_id_final(): "<< this->id<< endl;}
};

void class_function::printvalue()
{   
    cout<< " id: "<< id<< endl;
    cout<< " name: "<< name<< endl;

}

int main()
{   class_function salam(42, " Bukx");
    salam.printvalue();
    salam.Increase_id();
    salam.Increase_id_final();
    
    return 0;
}