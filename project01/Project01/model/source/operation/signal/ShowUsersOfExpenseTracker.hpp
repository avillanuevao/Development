#ifndef MODEL_OPERATION_SIGNAL_SHOWUSERSOFEXPENSETRACKER_HPP
#define MODEL_OPERATION_SIGNAL_SHOWUSERSOFEXPENSETRACKER_HPP

namespace model
{
namespace operation
{
namespace signal
{

class ShowUsersOfExpenseTracker
{
  public:
    ShowUsersOfExpenseTracker(int idExpenseTracker);

    int getIdExpenseTracker() const;

  private:
    int mIdExpenseTracker;
};

}  // namespace signal
}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_SIGNAL_SHOWUSERSOFEXPENSETRACKER_HPP
