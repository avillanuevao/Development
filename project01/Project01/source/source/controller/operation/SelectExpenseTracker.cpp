#include "SelectExpenseTracker.hpp"

namespace source
{
namespace controller
{
namespace operation
{


SelectExpenseTracker::SelectExpenseTracker(
    std::shared_ptr<model::operation::iAllExpensesTrackers> allExpensesTracker) :
  mAllExpensesTracker(allExpensesTracker)
{

}

void SelectExpenseTracker::selectExpenseTracker(int idExpenseTracker)
{
  mAllExpensesTracker->setExpenseTrackerSelected(idExpenseTracker);
}

}  // namespace operation
}  // namespace controller
}  // namespace source
