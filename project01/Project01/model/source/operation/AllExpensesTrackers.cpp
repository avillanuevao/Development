#include "AllExpensesTrackers.hpp"

namespace model
{
namespace operation
{

AllExpensesTrackers::AllExpensesTrackers()
{

}

void AllExpensesTrackers::registerExpenseTracker(int idExpenseTracker, std::string nameExpenseTracker)
{
  std::cout << "AllExpensesTrackers::registerExpenseTracker" << std::endl;
  std::shared_ptr<model::operation::iExpenseTracker> newExpenseTracker =
      std::make_shared<model::operation::ExpenseTracker>(idExpenseTracker, nameExpenseTracker);
  mAllExpenses[idExpenseTracker] = newExpenseTracker;

  model::operation::signal::AddExpenseTracker signal(idExpenseTracker, nameExpenseTracker);
  utils::designPattern::SignalPublisher<model::operation::signal::AddExpenseTracker>::notifySubscribers(signal);
}

std::shared_ptr<iExpenseTracker> AllExpensesTrackers::getExpenseTrackerById(int idExpenseTracker)
{
  return mAllExpenses[idExpenseTracker];
}

void AllExpensesTrackers::addUser(int idUser, int idExpenseTracker)
{
  mAllExpenses[idExpenseTracker]->addUser(idUser);
}

void AllExpensesTrackers::registerExpenseByUser(int idUser, int idExpenseTracker, int amount)
{
  mAllExpenses[idExpenseTracker]->registerExpenseByUser(idUser, amount);
}

int AllExpensesTrackers::getUserAmount(int idUser, int idExpenseTracker)
{
  return mAllExpenses[idExpenseTracker]->getUserAmount(idUser);
}

void AllExpensesTrackers::setExpenseTrackerSelected(int idExpenseTracker)
{
  mActualExpenseTrackerSelected = mAllExpenses[idExpenseTracker];

  model::operation::signal::ShowUsersOfExpenseTracker signal(idExpenseTracker);
  utils::designPattern::SignalPublisher<model::operation::signal::ShowUsersOfExpenseTracker>::notifySubscribers(signal);
}

}  // namespace operation
}  // namespace model
