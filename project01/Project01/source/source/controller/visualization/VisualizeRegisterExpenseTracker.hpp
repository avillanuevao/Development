#ifndef SOURCE_CONTROLLER_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP
#define SOURCE_CONTROLLER_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP

#include <memory>

#include <source/source/view/visualization/VisualizeRegisterExpenseTracker.hpp>

namespace source
{
namespace controller
{
namespace visualization
{

class VisualizeRegisterExpenseTracker
{
  public:
    VisualizeRegisterExpenseTracker(
        std::shared_ptr<source::view::visualization::VisualizeRegisterExpenseTracker> view);

    void expenseTrackerRegistered(int idExpenseTracker, std::string nameExpenseTracker);

  private:
    std::shared_ptr<source::view::visualization::VisualizeRegisterExpenseTracker> mView;
};

}  // namespace visualization
}  // namespace controller
}  // namespace source

#endif // SOURCE_CONTROLLER_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP
