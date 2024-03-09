#include "RegisterExpenseTracker.hpp"

namespace source
{
namespace controller
{
namespace operation
{

RegisterExpenseTracker::RegisterExpenseTracker(
    std::shared_ptr<model::operation::iAllExpensesTrackers> allExpenses) :
  mAllExpenses(allExpenses)
{

}

void RegisterExpenseTracker::registerExpenseTracker(int idExpense, std::string nameExpense)
{
  mAllExpenses->registerExpenseTracker(idExpense, nameExpense);
}

}  // namespace operation
}  // namespace controller
}  // namespace source
