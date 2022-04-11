#ifndef SimpleView_H
#define SimpleView_H

#include "vtkSmartPointer.h" // Required for smart pointer internal ivars.
#include <QMainWindow>

// Forward Qt class declarations
class Ui_SimpleView;

// Forward VTK class declarations
class vtkQtTableView;

class SimpleView : public QMainWindow
{
  Q_OBJECT

public:
  // Constructor/Destructor
  SimpleView();
  ~SimpleView() override;

public Q_SLOTS:

  virtual void slotOpenFile();
  virtual void slotExit();

protected:
protected Q_SLOTS:

private:
  vtkSmartPointer<vtkQtTableView> TableView;

  // Designer form
  Ui_SimpleView* ui;
};

#endif // SimpleView_H
