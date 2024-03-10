#ifndef MODEL_OPERATION_SIGNAL_USERADDED_HPP
#define MODEL_OPERATION_SIGNAL_USERADDED_HPP

namespace model
{
namespace operation
{
namespace signal
{

class UserAdded
{
  public:
    UserAdded(int idUser);

    int getIdUser() const;

  private:
    int mIdUser;
};

}  // namespace signal
}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_SIGNAL_USERADDED_HPP
