#include <iostream>
#include <iomanip>

int main() {
    std::string name;
    int price, temperature;
    bool hasCashback;
    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> std::boolalpha >>  hasCashback;
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;

    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    std::cout << name << '\n';

    std::cout << std::setfill('.') << std::setw(35) << std::left;
    std::cout << "Price:"  << std::uppercase << std::hex << std::setw(35) << std::right << price << '\n';

    std::cout << std::setfill('.') << std::setw(35) << std::left;
    std::cout << "Has cash-back:"  << std::boolalpha << std::setw(35) << std::right << hasCashback << '\n';

    std::cout << std::setfill('.') << std::setw(35) << std::left;
    std::cout << "Max temperature:" << std::dec  << std::showpos << std::setw(35) << std::right << temperature << '\n';


    system("pause");
    return 0;
}