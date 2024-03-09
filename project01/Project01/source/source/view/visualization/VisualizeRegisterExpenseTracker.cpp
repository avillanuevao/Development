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
  addItemsToComboBox(QString::fromStdString(nameExpenseTracker));
}

void VisualizeRegisterExpenseTracker::addItemsToComboBox(const QString& item)
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
        // Obtener el modelo del ComboBox
        QVariant modelVariant = comboBoxQML->property("model");
        if (modelVariant.canConvert<QStandardItemModel*>())
        {
          QStandardItemModel* model = qvariant_cast<QStandardItemModel*>(modelVariant);

          // Agregar el elemento al modelo
          model->appendRow(new QStandardItem(item));
        }
        else
        {
          std::cerr << "Error: Unable to convert model property to QStandardItemModel*." << std::endl;
        }
      }
      else
      {
        std::cerr << "Error: Unable to find QML object with id 'comboBoxObject'." << std::endl;
      }
    }
    else
    {
      std::cerr << "Error: Root object is not a QQuickWindow." << std::endl;
    }
  }
  else
  {
    std::cerr << "Error: No root objects found." << std::endl;
  }
}

}  // namespace visualization
}  // namespace view
}  // namespace source
