#ifndef MODEL_OPERATION_EXPENSETRACKER_HPP
#define MODEL_OPERATION_EXPENSETRACKER_HPP

#include <map>
#include <memory>
#include <vector>

#include <operation/iExpenseTracker.hpp>

namespace model
{
namespace operation
{

class ExpenseTracker :
    public model::operation::iExpenseTracker
{
  public:
    ExpenseTracker(int id, std::string name);

    void addUser(int idUser) override;
    void registerExpenseByUser(int idUser, int amount) override;
    int getExpenseId() const override;
    std::vector<int> getUsersId() const override;
    int getUserAmount(int idUser) override;

  private:
    int mId;
    std::string mName;
    std::map<int, int> mExpenseTracker; // idUser amountUser
};

#endif // MODEL_OPERATION_EXPENSETRACKER_HPP

}  // namespace operation
}  // namespace model
