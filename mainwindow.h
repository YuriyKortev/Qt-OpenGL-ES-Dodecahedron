#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_radioButton_toggled(bool checked);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);

    void on_horizontalSlider_3_sliderMoved(int position);

    void on_horizontalSlider_4_sliderMoved(int position);

    void on_horizontalSlider_5_sliderMoved(int position);

    void on_horizontalSlider_6_sliderMoved(int position);

    void on_horizontalSlider_7_sliderMoved(int position);

    void on_horizontalSlider_8_sliderMoved(int position);

    void on_horizontalSlider_9_sliderMoved(int position);

    void on_checkBox_3_toggled(bool checked);

    void on_horizontalSlider_10_sliderMoved(int position);

    void on_horizontalSlider_11_sliderMoved(int position);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
