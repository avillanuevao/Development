#include "RegisterUser.hpp"

namespace source
{
namespace view
{
namespace operation
{

RegisterUser::RegisterUser(std::shared_ptr<controller::operation::RegisterUser> controller) :
  mController(controller)
{

}

void RegisterUser::registerUser(QString nameUser)
{
  int idUser = ++mLastIdUser;
  mController->registerUser(idUser, nameUser.toStdString());
}

}  // namespace operation
}  // namespace view
}  // namespace source
