#include "AddExpenseTracker.hpp"

namespace model
{
namespace operation
{
namespace signal
{

AddExpenseTracker::AddExpenseTracker(int idExpenseTracker, std::string nameExpenseTracker) :
  mIdExpenseTracker(idExpenseTracker), mNameExpenseTracker(nameExpenseTracker)
{

}

int AddExpenseTracker::getIdExpenseTracker() const
{
  return mIdExpenseTracker;
}

const std::string& AddExpenseTracker::getNameExpenseTracker() const
{
  return mNameExpenseTracker;
}

}  // namespace signal
}  // namespace operation
}  // namespace model
