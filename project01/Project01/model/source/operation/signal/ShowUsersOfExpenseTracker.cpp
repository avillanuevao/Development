#include "ShowUsersOfExpenseTracker.hpp"

namespace model
{
namespace operation
{
namespace signal
{

ShowUsersOfExpenseTracker::ShowUsersOfExpenseTracker(int idExpenseTracker) :
  mIdExpenseTracker(idExpenseTracker)
{

}

int ShowUsersOfExpenseTracker::getIdExpenseTracker() const
{
  return mIdExpenseTracker;
}

}  // namespace signal
}  // namespace operation
}  // namespace model
