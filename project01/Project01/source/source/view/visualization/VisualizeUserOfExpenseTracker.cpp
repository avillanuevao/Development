#include "VisualizeUserOfExpenseTracker.hpp"

namespace source
{
namespace view
{
namespace visualization
{

VisualizeUserOfExpenseTracker::VisualizeUserOfExpenseTracker(QQmlApplicationEngine& engine, QObject* parent) :
  mEngine(engine), mParent(parent)
{

}

void VisualizeUserOfExpenseTracker::showUserOfExpenseTracker(int idExpenseTracker)
{
  std::vector<int> idUsers = mAllExpensesTrackers->getExpenseTrackerById(idExpenseTracker)->getUsersId();

  if (!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);

    if (rootWindow)
    {
      QObject* comboBoxQML = rootObject->findChild<QObject*>("selectUserComboBox", Qt::FindChildrenRecursively);
      if (comboBoxQML)
      {
        QVariant currentModel = comboBoxQML->property("model");
        QStringList listElements;

        if (currentModel.canConvert<QStringList>())
        {
          listElements = currentModel.value<QStringList>();

          for (int userId : idUsers)
          {
            listElements << QString::number(userId);
          }
        }
        else
        {
          for (int userId : idUsers)
          {
            listElements << QString::number(userId);
          }
        }

        comboBoxQML->setProperty("model", QVariant::fromValue(listElements));

        rootWindow->update();
      }
    }
  }
}

}  // namespace visualization
}  // namespace view
}  // namespace source
