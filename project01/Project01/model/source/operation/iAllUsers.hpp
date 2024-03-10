#ifndef MODEL_OPERATION_IALLUSERS_HPP
#define MODEL_OPERATION_IALLUSERS_HPP

#include <string>
#include <memory>

#include <operation/User.hpp>
#include <designPattern/SignalPublisher.hpp>
#include <operation/signal/UserAdded.hpp>

namespace model
{
namespace operation
{

class iAllUsers :
    public utils::designPattern::SignalPublisher<model::operation::signal::UserAdded>
{
  public:
    iAllUsers() = default;

    virtual void registerUser(int idUser, std::string nameUser) = 0;
    virtual  std::shared_ptr<model::operation::User> getUserById(int idUser) = 0;
};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_IALLUSERS_HPP
