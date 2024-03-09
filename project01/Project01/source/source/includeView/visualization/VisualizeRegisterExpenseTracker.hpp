#ifndef SOURCE_INCLUDEVIEW_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP
#define SOURCE_INCLUDEVIEW_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP

#include <memory>

#include <source/source/controller/visualization/VisualizeRegisterExpenseTracker.hpp>
#include <model/source/operation/signal/AddExpenseTracker.hpp>
#include <utils/source/designPattern/SignalSubscriber.hpp>

namespace source
{
namespace includeView
{
namespace visualization
{

class VisualizeRegisterExpenseTracker :
    public utils::designPattern::SignalSubscriber<model::operation::signal::AddExpenseTracker>
{
  public:
    VisualizeRegisterExpenseTracker(
        std::shared_ptr<source::controller::visualization::VisualizeRegisterExpenseTracker> controller);

    void recievedSignal(model::operation::signal::AddExpenseTracker signal) override;

  private:
    std::shared_ptr<source::controller::visualization::VisualizeRegisterExpenseTracker> mController;
};

}  // namespace visualization
}  // namespace includeView
}  // namespace source

#endif // SOURCE_INCLUDEVIEW_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP
