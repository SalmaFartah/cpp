#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat MyBur("Alice", 4);
        Form MyForm("form", 6, 3);
        std::cout << MyForm << std::endl;
        MyBur.signForm(MyForm);
        MyBur.signForm(MyForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
