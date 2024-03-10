#include "ShowAvailableUsersInclude.hpp"

namespace source
{
namespace includeView
{
namespace visualization
{

ShowAvailableUsersInclude::ShowAvailableUsersInclude(
    std::shared_ptr<controller::visualization::ShowAvailableUsers> controller) :
  mController(controller)
{

}

void ShowAvailableUsersInclude::recievedSignal(model::operation::signal::UserAdded signal)
{
  mController->showAvailableUsers(signal.getIdUser());
}

}  // namespace visualization
}  // namespace includeView
}  // namespace source
