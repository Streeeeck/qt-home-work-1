#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

class DialogAdd: public QDialog {
    Q_OBJECT
public:
     DialogAdd( QWidget* parent = 0 );
     QString getInput() const;

signals:
    void applied();
private:
    QLineEdit* m_edit;
};

#endif // DIALOGADD_H
