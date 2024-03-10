#include "UserAdded.hpp"

namespace model
{
namespace operation
{
namespace signal
{

UserAdded::UserAdded(int idUser) :
  mIdUser(idUser)
{

}

int UserAdded::getIdUser() const
{
  return mIdUser;
}

}  // namespace signal
}  // namespace operation
}  // namespace model
