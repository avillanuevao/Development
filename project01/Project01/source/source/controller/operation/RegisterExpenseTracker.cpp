#include "RegisterExpenseTracker.hpp"

namespace source
{
namespace controller
{
namespace operation
{

void RegisterExpenseTracker::registerExpenseTracker(int idExpense, std::string nameExpense)
{
  mAllExpenses->registerExpenseTracker(idExpense, nameExpense);
}

}  // namespace operation
}  // namespace controller
}  // namespace source
