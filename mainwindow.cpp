#include <QMessageBox>
#include <QFileDialog>
#include <QScreen>
#include <QDebug>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Dialogs_AddFigures/dialog_addnewfigure.h"
#include "dialog_drawablewindow.h"
#include "dialog_editfigures.h"
#include "Exception.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::MainWindow(ArrayOfObjectsOnScreen* lst, QWidget *parent)
    : QMainWindow(parent)
    , m_figures_on_screen(lst)
    , ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/resources/img/icon.ico"));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_add_clicked()
{
    Dialog_AddNewFigure dial_add(m_figures_on_screen, this);
    dial_add.setModal(true);
    dial_add.exec();
}

void MainWindow::on_btn_Display_clicked()
{
    Dialog_DrawableWindow render(m_figures_on_screen, this);
    render.setModal(true);
    render.exec();
}

void MainWindow::on_btn_edit_clicked()
{
    Dialog_EditFigures dial_edit(m_figures_on_screen, this);
    dial_edit.setModal(true);
    dial_edit.exec();
}

void MainWindow::on_btn_save_clicked()
{
    QSize size = qApp->screens()[0]->size();
    QMessageBox msgBox;
    msgBox.setGeometry(size.width()/2 - 244, size.height()/2 - 121, 244, 121);
    msgBox.setWindowTitle("Select File type");
    msgBox.setText("Select File type in which data will be saved:");
    QAbstractButton *btn_Binary = msgBox.addButton("Binary", QMessageBox::ActionRole);
    QAbstractButton *btn_Text = msgBox.addButton("Text", QMessageBox::ActionRole);
    QAbstractButton *btn_Cancel = msgBox.addButton("Cancel", QMessageBox::RejectRole);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.exec();
    if(msgBox.clickedButton() == btn_Binary){
        QString str = QFileDialog::getSaveFileName(this, "Choose folder");
        if(str != ""){
            std::ofstream fout(str.toStdString(), std::ios::binary);
            m_figures_on_screen->binary_save(fout);
            fout.close();
        }
    } else if(msgBox.clickedButton() == btn_Text){
        QString str = QFileDialog::getSaveFileName(this, "Choose folder");
        if(str != ""){
            std::ofstream fout(str.toStdString());
            m_figures_on_screen->text_save(fout);
            fout.close();
        }
    } else if(msgBox.clickedButton() == btn_Cancel){
        msgBox.close();
    }
    msgBox.close();
}

void MainWindow::on_btn_load_clicked()
{
    QSize size = qApp->screens()[0]->size();
    QMessageBox msgBox;
    msgBox.setGeometry(size.width()/2 - 244, size.height()/2 - 121, 244, 121);
    msgBox.setWindowTitle("Select File type");
    msgBox.setText("Select File type from what data will be loaded:");
    QAbstractButton *btn_Binary = msgBox.addButton("Binary", QMessageBox::ActionRole);
    QAbstractButton *btn_Text = msgBox.addButton("Text", QMessageBox::ActionRole);
    QAbstractButton *btn_Cancel = msgBox.addButton("Cancel", QMessageBox::RejectRole);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.exec();
    try{
        if(msgBox.clickedButton() == btn_Binary){
            msgBox.close();
            QString str = QFileDialog::getOpenFileName(this, "Choose folder");
            if(str != ""){
                std::ifstream fout(str.toStdString(), std::ios::binary);
                m_figures_on_screen->binary_load(fout);
                fout.close();
            }
        } else if(msgBox.clickedButton() == btn_Text){
            msgBox.close();
            QString str = QFileDialog::getOpenFileName(this, "Choose folder");
            if(str != ""){
                std::ifstream fout(str.toStdString());
                m_figures_on_screen->text_load(fout);
                fout.close();
            }
        } else if(msgBox.clickedButton() == btn_Cancel){
            msgBox.close();
            return;
        }
        QMessageBox::information(this, "Success!", "Figures successfuly loaded!");
    } catch (WrongInputFileException&) {
        QMessageBox::critical(this, "Error!", "File is unacceptable or corrupted! Please, try again");
    } catch (...){
        terminate();
    }
}
