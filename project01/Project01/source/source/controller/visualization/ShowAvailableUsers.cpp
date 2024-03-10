#include "ShowAvailableUsers.hpp"

namespace source
{
namespace controller
{
namespace visualization
{

ShowAvailableUsers::ShowAvailableUsers(std::shared_ptr<source::view::visualization::ShowAvailableUsers> view) :
  mView(view)
{

}

void ShowAvailableUsers::showAvailableUsers(int idUser)
{
  mView->showAvailableUser(idUser);
}

}  // namespace visualization
}  // namespace controller
}  // namespace source
