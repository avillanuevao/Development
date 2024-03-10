#ifndef SOURCE_VIEW_VISUALIZATION_SHOWAVAILABLEUSERS_HPP
#define SOURCE_VIEW_VISUALIZATION_SHOWAVAILABLEUSERS_HPP

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

#include <model/source/operation/iAllUsers.hpp>

namespace source
{
namespace view
{
namespace visualization
{

class ShowAvailableUsers :
    public QObject
{
    Q_OBJECT
  public:
    ShowAvailableUsers(std::shared_ptr<model::operation::iAllUsers> allUsers, QQmlApplicationEngine& engine, QObject* parent = nullptr);


    void showAvailableUser(int idUser);

  public slots:
    void addItemsToComboBox(const QString& item, const int& id);

  private:
    std::shared_ptr<model::operation::iAllUsers> mAllUsers;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace view
}  // namespace source

#endif // SOURCE_VIEW_VISUALIZATION_SHOWAVAILABLEUSERS_HPP
