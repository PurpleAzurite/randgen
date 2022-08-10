#ifndef RANDGEN_H
#define RANDGEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RandGen; }
QT_END_NAMESPACE

class RandGen : public QMainWindow
{
    Q_OBJECT

public:
    RandGen(QWidget *parent = nullptr);
    ~RandGen();

private:
    Ui::RandGen *ui;
    QMenu* m_fileMenu;
    QAction* m_generateAction;
    QAction* m_exitAction;
};
#endif // RANDGEN_H
