// =====================================================================================
// LValue / RValue
// =====================================================================================

module modern_cpp:rvalue_lvalue;

namespace LValueRValue {

    static void sayHelloInt(const int& message) {

        int m = message;
        std::cout << "Referenz" << message << std::endl;
    }

    //static void sayHelloInt(int message) {

    //    int m = message;

    //    std::cout << "´Copy" << message << std::endl;
    //}


    // lvalue reference
    static void sayHello(std::string& message) {
        std::cout << "sayHello [std::string&]:  " << message << std::endl;
    }

    // rvalue reference
    static void sayHello(std::string&& message) {
        std::cout << "sayHello [std::string&&]: " << message << std::endl;
    }

    static void test01() {

        std::string a = "Hello";
        std::string b = " World";

        sayHello(a);
        sayHello(a + b);   // Konkatenation // Aneinanderhängen
    }

    // -------------------------------------------------------------------

    static void helper(std::string&& message) {

        sayHello( std::move( message ) );  // LValue: Das Objekt hat nun einen Namen
                            
                            // RValue: Weil message vom Typ std::string&& ist
                                                                // sayHello(std::move(message));                  // casting an lvalue to an rvalue
        char ch = message.at(5);
    }

    static void test02() {

        // helper(std::string("Where are we going ..."));

        helper("Where are we going ...");
    }

    // -------------------------------------------------------------------

    static void test03() {

        std::string s = "Hello";

        sayHello(s);
        // versus
        sayHello(std::move(s));  // casts an lvalue to an rvalue
    }

    // -------------------------------------------------------------------

    static void test04() {

        // int& i = 2;          // invalid: reference to a constant

        // int a = 2;
        // int b = 3;

        // int& k = a + b;     // invalid: reference to a temporary

        int&& i = 2;           // works: reference to a constant

        int a = 2;
        int b = 3;

        int&& k = a + b;       // works: reference to a temporary
    }
}

void main_rvalue_lvalue()
{
    using namespace LValueRValue;

    int n = 123;

    sayHelloInt(n);

    test01();
    test02();
    test03();
    test04();
}

// =====================================================================================
// End-of-File
// =====================================================================================
