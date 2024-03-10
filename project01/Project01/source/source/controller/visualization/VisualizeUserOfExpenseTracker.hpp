#ifndef SOURCE_CONTROLLER_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP
#define SOURCE_CONTROLLER_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP

#include <memory>

#include <source/view/visualization/VisualizeUserOfExpenseTracker.hpp>

namespace source
{
namespace controller
{
namespace visualization
{

class VisualizeUserOfExpenseTracker
{
  public:
    VisualizeUserOfExpenseTracker(
        std::shared_ptr<source::view::visualization::VisualizeUserOfExpenseTracker> view);

    void showUserOfExpenseTracker(int idExpenseTracker);

  private:
    std::shared_ptr<source::view::visualization::VisualizeUserOfExpenseTracker> mView;
};

}  // namespace visualization
}  // namespace controller
}  // namespace source

#endif // SOURCE_CONTROLLER_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP
