#include "VisualizeUserOfExpenseTracker.hpp"

namespace source
{
namespace controller
{
namespace visualization
{

VisualizeUserOfExpenseTracker::VisualizeUserOfExpenseTracker(
    std::shared_ptr<view::visualization::VisualizeUserOfExpenseTracker> view) :
  mView(view)
{

}

void VisualizeUserOfExpenseTracker::showUserOfExpenseTracker(int idExpenseTracker)
{
  mView->showUserOfExpenseTracker(idExpenseTracker);
}

}  // namespace visualization
}  // namespace controller
}  // namespace source
