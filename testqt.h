#ifndef TESTQT_H
#define TESTQT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestQt;
}
QT_END_NAMESPACE

class TestQt : public QMainWindow
{
    Q_OBJECT

public:
    TestQt(QWidget *parent = nullptr);
    ~TestQt();

private:
    Ui::TestQt *ui;
};
#endif // TESTQT_H
