#include "VisualizeRegisterExpenseTracker.hpp"

namespace source
{
namespace includeView
{
namespace visualization
{

VisualizeRegisterExpenseTracker::VisualizeRegisterExpenseTracker(
    std::shared_ptr<controller::visualization::VisualizeRegisterExpenseTracker> controller) :
  mController(controller)
{

}

void VisualizeRegisterExpenseTracker::recievedSignal(model::operation::signal::AddExpenseTracker signal)
{
  mController->expenseTrackerRegistered(signal.getIdExpenseTracker(), signal.getNameExpenseTracker());
}

}  // namespace visualization
}  // namespace includeView
}  // namespace source
