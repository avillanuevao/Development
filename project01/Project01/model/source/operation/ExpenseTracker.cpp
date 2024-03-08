#include "ExpenseTracker.hpp"

namespace model
{
namespace operation
{

ExpenseTracker::ExpenseTracker(int id, std::string name):
  mId(id), mName(name)
{

}

void ExpenseTracker::addUser(int idUser)
{
  mExpenseTracker[idUser] = 0;
}

void ExpenseTracker::registerExpenseByUser(int idUser, int amount)
{
  auto it = mExpenseTracker.find(idUser);

  if (it == mExpenseTracker.end())
  {
    addUser(idUser);
  }

  mExpenseTracker[idUser] = mExpenseTracker[idUser] + amount;

}

int ExpenseTracker::getExpenseId() const
{
  return mId;
}

int ExpenseTracker::getUserAmount(int idUser)
{
  return mExpenseTracker[idUser];
}

}  // namespace operation
}  // namespace model
