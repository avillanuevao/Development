#ifndef SOURCE_CONTROLLER_OPERATION_SELECTEXPENSETRACKER_HPP
#define SOURCE_CONTROLLER_OPERATION_SELECTEXPENSETRACKER_HPP

#include <memory>

#include <model/source/operation/iAllExpensesTrackers.hpp>

namespace source
{
namespace controller
{
namespace operation
{

class SelectExpenseTracker
{
  public:
    SelectExpenseTracker(std::shared_ptr<model::operation::iAllExpensesTrackers> allExpensesTracker);

    void selectExpenseTracker(int idExpenseTracker);

  private:
    std::shared_ptr<model::operation::iAllExpensesTrackers> mAllExpensesTracker;
};

}  // namespace operation
}  // namespace controller
}  // namespace source

#endif // SOURCE_CONTROLLER_OPERATION_SELECTEXPENSETRACKER_HPP
