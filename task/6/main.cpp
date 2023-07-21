#include "recbook.hpp"

int main()
{
    Recbook recipeBook;
    std::vector<std::string> availableIngredients = {"Ingredient A", "Ingredient B"};
    std::cout << "Recipes that can be made with available ingredients:\n";
    recipeBook.findRec(availableIngredients);
}