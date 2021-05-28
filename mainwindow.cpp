#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QTableView;
    model = new QStandardItemModel();
    linklist = new MyQLinkList(model);
    ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//читаем из файла и выводим
{//СКЛАД ИД ВМЕСТИМОСТЬ ГОРОД АДРЕС
    linklist->clear();
    model->clear();

    QString val;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this,
                                                           tr("Open Json File"),
                                                           QString(),
                                                           tr("JSON (*.json)"));
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8(), &error);
    //qDebug() << "Error: " << error.errorString() << error.offset << error.error;

    if (doc.isObject())
    {
         QJsonObject json = doc.object();
         QJsonArray jsonArray = json["data"].toArray();

         foreach (const QJsonValue & value, jsonArray)
         {
             if (value.isObject())
             {
                 QJsonObject obj = value.toObject();
                 linklist->push(Storage(obj["id"].toString().toInt(),
                                  obj["capacity"].toString().toInt(),
                         obj["city"].toString(),
                         obj["address"].toString()));
              }
          }

    }

}

void MainWindow::on_pushButton_2_clicked()//запись в файл

{
    QString saveFileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Json File"),
                                                        QString(),
                                                        tr("JSON (*.json)"));

    QFileInfo fileInfo(saveFileName);   // С помощью QFileInfo
     QDir::setCurrent(fileInfo.path());  // установим текущую рабочую директорию, где будет файл, иначе может не заработать
     // Создаём объект файла и открываем его на запись
     QFile jsonFile(saveFileName);
     if (!jsonFile.open(QIODevice::WriteOnly))
     {
         qDebug()<<"файл не найден!\n";
         return;
     }

     QJsonObject curJsonObject;
     curJsonObject["data"] = linklist->toJSON();
     jsonFile.write(QJsonDocument(curJsonObject).toJson(QJsonDocument::Indented));
     jsonFile.close();
}



void MainWindow::on_pushButton_3_clicked()
{
    QDialog dlg(this);
    dlg.setWindowTitle(tr("Add to table"));

    QLineEdit *ledit1 = new QLineEdit(&dlg);
    QLineEdit *ledit2 = new QLineEdit(&dlg);
    QLineEdit *ledit3 = new QLineEdit(&dlg);
    QLineEdit *ledit4 = new QLineEdit(&dlg);

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(tr("id:"), ledit1);
    layout->addRow(tr("capacity:"), ledit2);
    layout->addRow(tr("city:"), ledit3);
    layout->addRow(tr("address:"), ledit4);
    layout->addWidget(btn_box);

    dlg.setLayout(layout);

    if(dlg.exec() == QDialog::Accepted) {
        const QString &str1 = ledit1->text();
        const QString &str2 = ledit2->text();
        const QString &str3 = ledit3->text();
        const QString &str4 = ledit4->text();
        linklist->push(Storage(str1.toInt(),
                               str2.toInt(),
                               str3,
                               str4));
    }



}

void MainWindow::on_pushButton_5_clicked()
{
    linklist->del(ui->tableView->currentIndex().row());
}

void MainWindow::on_pushButton_4_clicked()
{
    if(!ui->tableView->currentIndex().isValid())
        return;
    QDialog dlg(this);
    dlg.setWindowTitle(tr("Edit table item"));

    QLineEdit *ledit1 = new QLineEdit(&dlg);
    QLineEdit *ledit2 = new QLineEdit(&dlg);
    QLineEdit *ledit3 = new QLineEdit(&dlg);
    QLineEdit *ledit4 = new QLineEdit(&dlg);
    int _id = ui->tableView->currentIndex().row();
    Storage st = linklist->getData(_id);

    ledit1->setText(QString::number(st.getId()));
    ledit2->setText(QString::number(st.getCapacity()));
    ledit3->setText(st.getCity());
    ledit4->setText(st.getAddress());

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(tr("id:"), ledit1);
    layout->addRow(tr("capacity:"), ledit2);
    layout->addRow(tr("city:"), ledit3);
    layout->addRow(tr("address:"), ledit4);
    layout->addWidget(btn_box);

    dlg.setLayout(layout);
    if(dlg.exec() == QDialog::Accepted) {
        const QString &str1 = ledit1->text();
        const QString &str2 = ledit2->text();
        const QString &str3 = ledit3->text();
        const QString &str4 = ledit4->text();
        linklist->edit(Storage(str1.toInt(),
                               str2.toInt(),
                               str3,
                               str4),_id);
    }
}
