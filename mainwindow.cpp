#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("127.0.0.1");
    db.setHostName("localhost");
    db.setUserName("root");//default mysql username for xampp is 'root'
    db.setPassword(""); // xampp mysql has no password is default
    db.setDatabaseName("qt_lab10_database");

    if (db.open()) {
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
            }
    else{
        QMessageBox::information(this, "Not Connection", "Database Is Not Connected");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    string userid, username, usertown;

    QSqlQuery mySqlQuery;
    mySqlQuery.exec("SELECT * FROM users");

    if (mySqlQuery.size() > 0) {
        while (mySqlQuery.next()) {


            userid = mySqlQuery.value("id").toString().toUtf8().constData();//convert result to string
            username = mySqlQuery.value("name").toString().toUtf8().constData();
            usertown = mySqlQuery.value("town").toString().toUtf8().constData();


            ui->textEdit->insertPlainText(QString::fromStdString(userid +  " - " +  username + " - " + usertown + "\n"));
            ui->textEdit->moveCursor (QTextCursor::End);
        }
    }
}
