#ifndef MODEL_OPERATION_IEXPENSETRACKER_HPP
#define MODEL_OPERATION_IEXPENSETRACKER_HPP

#include <vector>

namespace model
{
namespace operation
{

class iExpenseTracker
{
  public:
    iExpenseTracker() = default;

    virtual void addUser(int idUser) = 0;
    virtual void registerExpenseByUser(int idUser, int amount) = 0;
    virtual int getExpenseId() const = 0;
    virtual std::vector<int> getUsersId() const = 0;
    virtual int getUserAmount(int idUser) = 0;
};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_IEXPENSETRACKER_HPP
