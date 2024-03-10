#ifndef SOURCE_CONTROLLER_VISUALIZATION_SHOWAVAILABLEUSERS_HPP
#define SOURCE_CONTROLLER_VISUALIZATION_SHOWAVAILABLEUSERS_HPP

#include <memory>

#include <source/view/visualization/ShowAvailableUsers.hpp>

namespace source
{
namespace controller
{
namespace visualization
{

class ShowAvailableUsers
{
  public:
    ShowAvailableUsers(std::shared_ptr<source::view::visualization::ShowAvailableUsers> view);

    void showAvailableUsers(int idUser);

  private:
    std::shared_ptr<source::view::visualization::ShowAvailableUsers> mView;
};

}  // namespace visualization
}  // namespace controller
}  // namespace source

#endif // SOURCE_CONTROLLER_VISUALIZATION_SHOWAVAILABLEUSERS_HPP
