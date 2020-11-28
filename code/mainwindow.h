#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMouseEvent>
#include <QQueue>
#include <QPropertyAnimation>
#include <QWheelEvent>

#include "Tree/Graphics/GraphicsLinkCutTree.h"
#include "Tree/Node.h"
#include "Helpers/Sequance.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
               class Frame; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void showEvent(QShowEvent *) override;
    void resizeEvent(QResizeEvent *) override;
    void mousePressEvent(QMouseEvent *e) override;
    void wheelEvent(QWheelEvent *e) override;

    void on_pushButtonMakeStepClicked();

    void on_horizontalSliderAnimationSpeedValueChanged(int value);

    void on_pushButtonResetClicked();

    void on_pushButtonExposeClicked();

    void on_pushButtonCutClicked();

    void on_pushButtonLinkClicked();

    void on_pushButtonEndOperationClicked();

    void on_pushButtonOpenPresetsClicked();

    void on_pushButtonPreset1Clicked();
    void on_pushButtonPreset2Clicked();
    void on_pushButtonPreset3Clicked();
    void on_pushButtonPreset4Clicked();
    void on_pushButtonPreset5Clicked();
    void on_pushButtonPreset6Clicked();
    void on_pushButtonPreset7Clicked();
    void on_pushButtonPreset8Clicked();

private:
    Ui::MainWindow *ui_base;
    Ui::Frame *ui_main;

    QPropertyAnimation * showPresetsListAnimation;
    QPropertyAnimation * hidePresetsListAnimation;

    GraphicsLinkCutTree graphics_tree;
    LinkCutTree * tree;
    QQueue<GraphicsSolidNodeItem*> selected_nodes;

    void init();
};
#endif // MAINWINDOW_H
