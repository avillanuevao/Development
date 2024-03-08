#ifndef MODEL_OPERATION_IALLEXPENSESTRACKERS_HPP
#define MODEL_OPERATION_IALLEXPENSESTRACKERS_HPP

#include <memory>
#include <string>

#include <operation/iExpenseTracker.hpp>

namespace model
{
namespace operation
{

class iAllExpensesTrackers
{
  public:
    iAllExpensesTrackers() = default;

    virtual void registerExpenseTracker(int idExpenseTracker, std::string nameExpenseTracker) = 0;
    virtual std::shared_ptr<model::operation::iExpenseTracker> getExpenseTrackerById(int idExpenseTracker) = 0;
    virtual void addUser(int idUser, int idExpenseTracker) = 0;
    virtual void registerExpenseByUser(int idUser, int idExpenseTracker, int amount) = 0;
    virtual int getUserAmount(int idUser, int idExpenseTracker) = 0;
    virtual void setExpenseTrackerSelected(int idExpenseTracker) = 0;
};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_IALLEXPENSESTRACKERS_HPP
