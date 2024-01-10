#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_plateManager = new plateManager();

    QRegularExpression reg;
    reg.setPattern("^[A-Z0-9]{8}$");

    QRegularExpressionValidator* val = new QRegularExpressionValidator(reg,this);
    ui->tx_input->setValidator(val);

    ui->tx_input->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_plateManager;
}


void MainWindow::on_cb_type_currentIndexChanged(int index)
{
    ui->tx_generateNum->clear();
    ui->tx_processNum->clear();
    m_list.clear();
    m_inputlist.clear();
    m_inputType = index;
    switch (index) {
    case 0:
        ui->tx_input->setEnabled(false);
        break;
    case 1:
        ui->tx_input->setEnabled(true);
        break;
    }
}




void MainWindow::on_btn_sort_clicked()
{
    ui->tx_processNum->clear();
    m_map.clear();
    switch (m_inputType) {
    case 0:
        for(QString i:m_list){
            m_map.insert(i,i);
        }
        ui->tx_processNum->addItems(m_map.keys());
        break;
    case 1:
        for(QString i:m_inputlist){
            m_map.insert(i,i);
        }
        ui->tx_processNum->addItems(m_map.keys());
        break;
    }
}


void MainWindow::on_btn_generate_clicked()
{
    m_list.clear();
    if(m_inputType == 0){
        ui->tx_generateNum->clear();
        int number = ui->spin_number->value();
        for(int i=0;i<number;i++){
            QString rand = m_plateManager->getRandomString(8);
            m_list.append(rand);
        }

    }else {
        bool isAllNumber = false;
        bool isHasNumber = false;
        QString tx = ui->tx_input->text();
        if(tx.size() <8){
            QMessageBox::warning(this,"提示","输入车牌号少于8位!");
            return;
        }
        tx.toInt(&isAllNumber);
        for(int i =0;i < tx.size();++i){
            isHasNumber = tx.at(i).isNumber();
            if(isHasNumber){
                break;
            }
        }
        if(isAllNumber || !isHasNumber){
            QMessageBox::warning(this,"提示","输入车牌号应字母数字混合!");
            return;
        }
        m_list.append(ui->tx_input->text());
        m_inputlist.append(ui->tx_input->text());
    }
    ui->tx_generateNum->addItems(m_list);
}


void MainWindow::on_btn_find_clicked()
{
    if(m_list.isEmpty()){
        QMessageBox::warning(this,"提示","还未生成车牌!");
        return;
    }
    if(ui->tx_findInput->text().isEmpty()){
        QMessageBox::warning(this,"提示","查找车牌关键字为空!");
        return;
    }
    QString inputTx = ui->tx_findInput->text();
    m_map.clear();
    ui->tx_findNum->clear();
    switch (m_inputType) {
    case 0:
        for(QString i:m_list){
            if(i.contains(inputTx)){
                m_map.insert(i,i);
            }
        }
        ui->tx_findNum->addItems(m_map.keys());
        break;
    case 1:
        for(QString i:m_inputlist){
            if(i.contains(inputTx)){
                m_map.insert(i,i);
            }
        }
        ui->tx_findNum->addItems(m_map.keys());
        break;
    }
}

