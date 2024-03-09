#include "VisualizeRegisterExpenseTracker.hpp"

namespace source
{
namespace controller
{
namespace visualization
{

VisualizeRegisterExpenseTracker::VisualizeRegisterExpenseTracker(
    std::shared_ptr<view::visualization::VisualizeRegisterExpenseTracker> visualize) :
  mVisualize(visualize)
{

}

void VisualizeRegisterExpenseTracker::expenseTrackerRegistered(int idExpenseTracker, std::string nameExpenseTracker)
{
  mVisualize->expenseTrackerRegistered(idExpenseTracker, nameExpenseTracker);
}

}  // namespace visualization
}  // namespace controller
}  // namespace source
