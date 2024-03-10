#include "ShowAvailableUsers.hpp"

namespace source
{
namespace view
{
namespace visualization
{

ShowAvailableUsers::ShowAvailableUsers(std::shared_ptr<model::operation::iAllUsers> allUsers,
                                       QQmlApplicationEngine& engine, QObject* parent) :
  mAllUsers(allUsers), mEngine(engine), mParent(parent)
{

}

void ShowAvailableUsers::showAvailableUser(int idUser)
{
  QString item = QString::fromStdString(mAllUsers->getUserById(idUser)->getName());

  addItemsToComboBox(item, idUser);
}

void ShowAvailableUsers::addItemsToComboBox(const QString& item, const int& id)
{
  if (!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);

    if (rootWindow)
    {
      QObject* comboBoxQML = rootObject->findChild<QObject*>("selectUserAvailableComboBox", Qt::FindChildrenRecursively);
      if (comboBoxQML)
      {
        QVariant currentModel = comboBoxQML->property("model");
        QStringList listElements;

        if (currentModel.canConvert<QStringList>())
        {
          listElements = currentModel.value<QStringList>();
          listElements << item;
        }
        else
        {
          listElements << item;
        }

        comboBoxQML->setProperty("model", QVariant::fromValue(listElements));

        rootWindow->update();
      }
      QVariantMap userAvailableMap = rootWindow->property("userAvailableMap").toMap();
      userAvailableMap.insert(item, id);
      rootWindow->setProperty("userAvailableMap", userAvailableMap);
    }
  }
}

}  // namespace visualization
}  // namespace view
}  // namespace source
