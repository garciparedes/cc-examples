#include <iostream>
#include <sstream>
using namespace std;

class Student {

    private:

        int age;
        string first_name;
        string last_name;
        int standard;

    public:

        void set_age(int value) {
            age = value;
        }

        void set_first_name(string value) {
            first_name = value;
        }

        void set_last_name(string value) {
            last_name = value;
        }

        void set_standard(int value) {
            standard = value;
        }

        int get_age() {
            return age;
        }

        string get_first_name() {
            return first_name;
        }
        
        string get_last_name() {
            return last_name;
        }

        int get_standard() {
            return standard;
        }

        string to_string() {
            stringstream ss;
            char coma = ',';
            ss << get_age() << coma <<
                get_first_name() << coma <<
                get_last_name() << coma <<
                get_standard();
            return ss.str();
        }

};


int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

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
