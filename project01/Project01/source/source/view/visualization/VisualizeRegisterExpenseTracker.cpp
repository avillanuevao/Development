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
        // Obtiene el modelo actual del QComboBox
        QVariant currentModel = comboBoxQML->property("model");
        QStringList listaColores;

        // Si el modelo actual es una lista, agrégale elementos
        if (currentModel.canConvert<QStringList>())
        {
          listaColores = currentModel.value<QStringList>();
          listaColores << item; // Agrega el nuevo elemento
        }
        else
        {
          // Si no hay un modelo actual, crea uno nuevo
          listaColores << item;
        }

        // Establece el modelo actualizado en el QComboBox
        comboBoxQML->setProperty("model", QVariant::fromValue(listaColores));

        // Actualiza la interfaz gráfica
        rootWindow->update();
      }
    }
  }
}

}  // namespace visualization
}  // namespace view
}  // namespace source
