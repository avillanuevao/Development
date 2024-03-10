#include "VisualizeRegisterExpenseTracker.hpp"

namespace source
{
namespace view
{
namespace visualization
{

VisualizeRegisterExpenseTracker::VisualizeRegisterExpenseTracker(QQmlApplicationEngine& engine, QObject* parent) :
  mEngine(engine), mParent(parent)
{

}

void VisualizeRegisterExpenseTracker::expenseTrackerRegistered(int idExpenseTracker, std::string nameExpenseTracker)
{
  addItemsToComboBox(QString::fromStdString(nameExpenseTracker), idExpenseTracker);
}

void VisualizeRegisterExpenseTracker::addItemsToComboBox(const QString& item, const int& id)
{
  if (!mEngine.rootObjects().isEmpty())
  {
    QObject* rootObject = mEngine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);

    if (rootWindow)
    {
      QObject* comboBoxQML = rootObject->findChild<QObject*>("selectExpenseTrackerComboBox", Qt::FindChildrenRecursively);
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
      QVariantMap expenseTrackerMap = rootWindow->property("expenseTrackerMap").toMap();
      expenseTrackerMap.insert(item, id);
      rootWindow->setProperty("expenseTrackerMap", expenseTrackerMap);
    }
  }
}

}  // namespace visualization
}  // namespace view
}  // namespace source
