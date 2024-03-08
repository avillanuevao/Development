#include "RegisterExpenseTracker.hpp"

namespace source
{
namespace view
{
namespace operation
{

RegisterExpenseTracker::RegisterExpenseTracker(std::shared_ptr<source::controller::operation::RegisterExpenseTracker> controller) :
  mController(controller)
{

}

void RegisterExpenseTracker::registerExpenseTracker(int idExpense, std::string nameExpense)
{
  mController->registerExpenseTracker(idExpense, nameExpense);
}

}  // namespace operation
}  // namespace view
}  // namespace source
