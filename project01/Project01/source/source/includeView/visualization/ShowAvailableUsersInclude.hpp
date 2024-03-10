#ifndef SOURCE_INCLUDEVIEW_VISUALIZATION_SHOWAVAILABLEUSERSINCLUDE_HPP
#define SOURCE_INCLUDEVIEW_VISUALIZATION_SHOWAVAILABLEUSERSINCLUDE_HPP

#include <memory>

#include <designPattern/SignalSubscriber.hpp>
#include <model/source/operation/signal/UserAdded.hpp>
#include <source/controller/visualization/ShowAvailableUsers.hpp>

namespace source
{
namespace includeView
{
namespace visualization
{

class ShowAvailableUsersInclude :
    public utils::designPattern::SignalSubscriber<model::operation::signal::UserAdded>
{
  public:
    ShowAvailableUsersInclude(std::shared_ptr<source::controller::visualization::ShowAvailableUsers> controller);

    void recievedSignal(model::operation::signal::UserAdded signal) override;

  private:
    std::shared_ptr<source::controller::visualization::ShowAvailableUsers> mController;
};

}  // namespace visualization
}  // namespace includeView
}  // namespace source

#endif // SOURCE_INCLUDEVIEW_VISUALIZATION_SHOWAVAILABLEUSERSINCLUDE_HPP
