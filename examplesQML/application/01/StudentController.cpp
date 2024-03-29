#include "StudentController.hpp"

StudentController::StudentController(std::shared_ptr<StudentModel> studentModel, std::shared_ptr<SceneCreator> sceneCreator)
    : m_studentModel(studentModel), m_sceneCreator(sceneCreator) {
    // Lógica de inicialización si es necesario...
}

void StudentController::setStudentName(QString name)
{
    m_studentModel->setName(name);
    emit studentNameChanged();
}

void StudentController::setStudentId(int id)
{
    m_studentModel->setId(id);
    emit studentIdChanged();
}

QString StudentController::getStudentName()
{
    return m_studentModel->getName();
}

int StudentController::getStudentId()
{
    return m_studentModel->getId();
}

void StudentController::updateView()
{
    m_studentView.printStudentDetails(m_studentModel->getName(), m_studentModel->getId());
}
