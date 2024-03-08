#ifndef MODEL_OPERATION_ALLEXPENSESTRACKERS_HPP
#define MODEL_OPERATION_ALLEXPENSESTRACKERS_HPP

#include <map>
#include <memory>
#include <string>

#include <operation/iExpenseTracker.hpp>
#include <operation/ExpenseTracker.hpp>
#include <operation/iAllExpensesTrackers.hpp>
#include <operation/iAllUsers.hpp>

namespace model
{
namespace operation
{

class AllExpensesTrackers :
    public model::operation::iAllExpensesTrackers
{
  public:
    AllExpensesTrackers();

    void registerExpenseTracker(int idExpenseTracker, std::string nameExpenseTracker) override;
    std::shared_ptr<model::operation::iExpenseTracker> getExpenseTrackerById(int idExpenseTracker) override;
    void addUser(int idUser, int idExpenseTracker) override;
    void registerExpenseByUser(int idUser, int idExpenseTracker, int amount) override;
    int getUserAmount(int idUser, int idExpenseTracker) override;
    void setExpenseTrackerSelected(int idExpenseTracker) override;

  private:
    std::shared_ptr<model::operation::iAllUsers> mAllUsers;
    std::map<int, std::shared_ptr<model::operation::iExpenseTracker>> mAllExpenses;
    std::shared_ptr<model::operation::iExpenseTracker> mActualExpenseTrackerSelected;

};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_ALLEXPENSESTRACKERS_HPP
