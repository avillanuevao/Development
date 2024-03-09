#ifndef MODEL_OPERATION_SIGNAL_ADDEXPENSETRACKER_HPP
#define MODEL_OPERATION_SIGNAL_ADDEXPENSETRACKER_HPP

#include <iostream>

namespace model
{
namespace operation
{
namespace signal
{

class AddExpenseTracker
{
  public:
    AddExpenseTracker(int idExpenseTracker, std::string nameExpenseTracker);

    int getIdExpenseTracker() const;

    const std::string& getNameExpenseTracker() const;

  private:
    int mIdExpenseTracker;
    std::string mNameExpenseTracker;
};

}  // namespace signal
}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_SIGNAL_ADDEXPENSETRACKER_HPP
