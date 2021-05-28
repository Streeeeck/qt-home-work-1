#include "dialogadd.h"

DialogAdd::DialogAdd( QWidget* parent ) : QDialog( parent ) {
    QBoxLayout* layout = new QHBoxLayout;
    m_edit = new QLineEdit;
    layout->addWidget( m_edit );

    QPushButton* okBtn = new QPushButton( "OK" );
    connect( okBtn, SIGNAL( clicked() ), SLOT( accept() ) );
    layout->addWidget( okBtn );

    QPushButton* applyBtn = new QPushButton( "Apply" );
    connect( applyBtn, SIGNAL( clicked() ), SIGNAL( applied() ) );
    layout->addWidget( applyBtn);

    QPushButton* cancelBtn = new QPushButton( "Cancel" );
    connect( cancelBtn, SIGNAL( clicked() ), SLOT( reject() ) );
    layout->addWidget( cancelBtn );

    this->setModal(1);
    setLayout( layout );
}

QString DialogAdd::getInput() const {
    return m_edit->text();
}
