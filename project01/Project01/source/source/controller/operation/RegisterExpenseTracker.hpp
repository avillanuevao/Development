#ifndef SOURCE_CONTROLLER_OPERATION_REGISTEREXPENSETRACKER_HPP
#define SOURCE_CONTROLLER_OPERATION_REGISTEREXPENSETRACKER_HPP

#include <model/source/operation/iAllExpensesTrackers.hpp>

namespace source
{
namespace controller
{
namespace operation
{

class RegisterExpenseTracker
{
  public:
    RegisterExpenseTracker();

    void registerExpenseTracker(int idExpense, std::string nameExpense);

  private:
    std::shared_ptr<model::operation::iAllExpensesTrackers> mAllExpenses;
};

}  // namespace operation
}  // namespace controller
}  // namespace source

#endif // SOURCE_CONTROLLER_OPERATION_REGISTEREXPENSETRACKER_HPP
