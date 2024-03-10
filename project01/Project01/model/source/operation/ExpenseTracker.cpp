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

std::vector<int> ExpenseTracker::getUsersId() const
{
  std::vector<int> idUsers;

  for (const auto& pair : mExpenseTracker)
  {
    idUsers.push_back(pair.first);
  }

  return idUsers;
}

int ExpenseTracker::getUserAmount(int idUser)
{
  return mExpenseTracker[idUser];
}

}  // namespace operation
}  // namespace model
