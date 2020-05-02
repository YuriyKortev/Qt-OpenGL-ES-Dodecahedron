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



void MainWindow::on_radioButton_toggled(bool checked)
{
    ui->scene_widget->setProject(checked);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->scene_widget->setAngleX(position);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->scene_widget->setAngleY(position);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->scene_widget->setFace(checked);
}

void MainWindow::on_checkBox_2_toggled(bool checked)
{
    ui->scene_widget->setAxes(checked);
}

void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    ui->scene_widget->setAngleZ(position);
}

void MainWindow::on_horizontalSlider_4_sliderMoved(int position)
{
    ui->scene_widget->setScX(((float)(position))/10.0f);
}

void MainWindow::on_horizontalSlider_5_sliderMoved(int position)
{
    ui->scene_widget->setScY(((float)(position))/10.0f);
}

void MainWindow::on_horizontalSlider_6_sliderMoved(int position)
{
    ui->scene_widget->setScZ(((float)(position))/10.0f);
}

void MainWindow::on_horizontalSlider_7_sliderMoved(int position)
{
    ui->scene_widget->setTrX(((float)(position))/10.0f);
}

void MainWindow::on_horizontalSlider_8_sliderMoved(int position)
{
    ui->scene_widget->setTrY(((float)(position))/10.0f);
}

void MainWindow::on_horizontalSlider_9_sliderMoved(int position)
{
    ui->scene_widget->setTrZ(((float)(position))/10.0f);
}

void MainWindow::on_checkBox_3_toggled(bool checked)
{
    ui->scene_widget->setFill(checked);
}

void MainWindow::on_horizontalSlider_10_sliderMoved(int position)
{
    ui->scene_widget->setResolution(position);
}

void MainWindow::on_horizontalSlider_11_sliderMoved(int position)
{
    ui->scene_widget->setLight((float)position/1000.0f);
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    ui->scene_widget->setType(GL_POLYGON);
}

void MainWindow::on_radioButton_4_toggled(bool checked)
{
    ui->scene_widget->setType(GL_TRIANGLE_FAN);
}

void MainWindow::on_horizontalSlider_12_sliderMoved(int position)
{
    ui->scene_widget->setDeep(position);
}

void MainWindow::on_radioButton_5_toggled(bool checked)
{
    ui->scene_widget->setMat(checked);
}

void MainWindow::on_pushButton_clicked()
{
    ui->scene_widget->setCamXY();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->scene_widget->setCamXZ();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->scene_widget->setCamYZ();
}
