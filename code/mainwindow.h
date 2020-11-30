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
#include "FrameUiComponetns.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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

    void fit_tree_in_view();

private:
    Ui::MainWindow * ui;
    FrameUiComponetns * ui_components_frame;

    QTimer *timer_fit_in_view;


    GraphicsLinkCutTree graphics_tree;
    LinkCutTree * tree;
    QQueue<GraphicsSolidNodeItem*> selected_nodes;

};
#endif // MAINWINDOW_H
