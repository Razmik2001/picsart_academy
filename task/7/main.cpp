#include "sys.hpp"

int main() {
    Expense expense1(50, "Groceries", "Food");
    Expense expense2(50, "Gr", "s");
    sys expenseSystem("John");
    expenseSystem.addExp(&expense1);
    expenseSystem.addExp(&expense2);
    std::cout << "All Expenses:\n";
    expenseSystem.display();
    std::cout << "\nFood Expenses:\n";
    expenseSystem.display("Food");
    expenseSystem.saveExp();
    expenseSystem.saveExp("Food");

    return 0;
}






