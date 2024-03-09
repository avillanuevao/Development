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

void RegisterExpenseTracker::registerExpenseTracker(QString nameExpense)
{
  int idExpense = ++mLastIdExpenseTracker;
  mController->registerExpenseTracker(idExpense, nameExpense.toStdString());
}

}  // namespace operation
}  // namespace view
}  // namespace source
