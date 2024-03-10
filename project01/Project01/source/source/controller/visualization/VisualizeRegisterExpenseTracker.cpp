#include "VisualizeRegisterExpenseTracker.hpp"

namespace source
{
namespace controller
{
namespace visualization
{

VisualizeRegisterExpenseTracker::VisualizeRegisterExpenseTracker(
    std::shared_ptr<view::visualization::VisualizeRegisterExpenseTracker> view) :
  mView(view)
{

}

void VisualizeRegisterExpenseTracker::expenseTrackerRegistered(int idExpenseTracker, std::string nameExpenseTracker)
{
  mView->expenseTrackerRegistered(idExpenseTracker, nameExpenseTracker);
}

}  // namespace visualization
}  // namespace controller
}  // namespace source
