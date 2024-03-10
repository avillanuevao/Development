#include "VisualizeUserOfExpenseTracker.hpp"

namespace source
{
namespace includeView
{
namespace visualization
{

VisualizeUserOfExpenseTracker::VisualizeUserOfExpenseTracker(
    std::shared_ptr<controller::visualization::VisualizeUserOfExpenseTracker> controller) :
  mController(controller)
{

}

void VisualizeUserOfExpenseTracker::recievedSignal(model::operation::signal::ShowUsersOfExpenseTracker signal)
{
  mController->showUserOfExpenseTracker(signal.getIdExpenseTracker());
}

}  // namespace visualization
}  // namespace includeView
}  // namespace source
