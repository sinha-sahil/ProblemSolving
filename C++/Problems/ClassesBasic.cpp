#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
    int age, standard;
    string first_name, last_name;
    public:
    void set_standard(int value){
        standard= value;
    }
    void set_age(int value){
        age= value;
    }
    void set_first_name(string value){
        first_name= value;
    }
    void set_last_name(string value){
        last_name= value;
    }
    int get_age(){
        return age;
    }
    int get_standard(){
        return standard;
    }
    string get_first_name(){
        return first_name;
    }
    string get_last_name(){
        return last_name;
    }
    
    string to_string(){
        string value=  to_string(age)+"," + first_name + "," + last_name + ","+ to_string(standard);
       return value;
    }
   
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    //cout<<to_string(age);
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
