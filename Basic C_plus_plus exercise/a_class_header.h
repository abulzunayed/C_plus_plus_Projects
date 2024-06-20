# ifndef A_CLASS_HEADER_H
# define A_CLASS_HEADER_H


class sally
{
public:
    
    sally( );    // constructor
    ~sally();    // deconstructor
    void printcrap();

    void setName(char x);
    char getName();
    void printshiz();
    void printshiz2() const;   // constant object
    sally( int a, const int b);    // constructor

/*     // member initilizer 
    sally(int a, int b);
    void print2();
 */

private:
    char name2;
    //int regvar;  // member intializer
    //const int canstvar;  // member intializer


};





#endif
