#include "SelectExpenseTracker.hpp"

namespace source
{
namespace view
{
namespace operation
{

SelectExpenseTracker::SelectExpenseTracker(
    std::shared_ptr<source::controller::operation::SelectExpenseTracker> controller) :
  mController(controller)
{

}

void SelectExpenseTracker::selectExpenseTracker(int idExpenseTracker)
{
  mController->selectExpenseTracker(idExpenseTracker);
}

}  // namespace operation
}  // namespace view
}  // namespace source
