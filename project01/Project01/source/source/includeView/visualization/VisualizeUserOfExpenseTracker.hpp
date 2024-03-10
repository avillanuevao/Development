#ifndef SOURCE_INCLUDEVIEW_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP
#define SOURCE_INCLUDEVIEW_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP

#include <memory>

#include <model/source/operation/signal/ShowUsersOfExpenseTracker.hpp>
#include <source/source/controller/visualization/VisualizeUserOfExpenseTracker.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace source
{
namespace includeView
{
namespace visualization
{

class VisualizeUserOfExpenseTracker :
    public utils::designPattern::SignalSubscriber<model::operation::signal::ShowUsersOfExpenseTracker>
{
  public:
    VisualizeUserOfExpenseTracker(
        std::shared_ptr<source::controller::visualization::VisualizeUserOfExpenseTracker> controller);

    void recievedSignal(model::operation::signal::ShowUsersOfExpenseTracker signal) override;

  private:
    std::shared_ptr<source::controller::visualization::VisualizeUserOfExpenseTracker> mController;
};

}  // namespace visualization
}  // namespace includeView
}  // namespace source

#endif // SOURCE_INCLUDEVIEW_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP
