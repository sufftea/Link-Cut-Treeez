#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_FrameUiComponetns.h"

#include "Helpers/Colors.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui_components_frame = new FrameUiComponetns(graphics_tree, selected_nodes, ui->graphicsView, this);

    // add layouts
    QGridLayout *gl1 = new QGridLayout(this->centralWidget());
    this->centralWidget()->setLayout(gl1);
    gl1->setContentsMargins(0, 0, 0, 0);
    gl1->addWidget(ui_components_frame, 0, 0);
    gl1->addWidget(ui->graphicsView, 0, 0);



    // set other stuff
    graphics_tree.set_animation_easing_curve(Animation::ease_in_out_circ);
    tree = & graphics_tree.tree;

    ui->graphicsView->setScene(graphics_tree.get_concrete_tree_scene());
    ui->graphicsView->setRenderHints(QPainter::RenderHint::Antialiasing);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
    // set background tiling for the graphicsview
    QPixmap tile(20, 20);
    QPainter painter(&tile);
    QPen black_pen(QColor(45,45,45));
    black_pen.setWidth(3);

    painter.setPen(black_pen);
    painter.fillRect(tile.rect(), MyColors::black);
    painter.drawPoint(10, 10);

    ui->graphicsView->setBackgroundBrush(tile);
//    ui->graphicsView->setBackgroundBrush(MyColors::black);


    selected_nodes.reserve(3);


    timer_fit_in_view = new QTimer(this);
    connect(timer_fit_in_view, &QTimer::timeout, this, &MainWindow::fit_tree_in_view);
    timer_fit_in_view->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{

}

void MainWindow::resizeEvent(QResizeEvent *)
{

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    e->accept();


    QGraphicsView * gw = ui->graphicsView;
    QPoint pos = gw->mapToScene(gw->mapFromParent(e->pos())).toPoint();


    Node * node = graphics_tree.node_at(pos);


    if (node != nullptr) {
        if (node->concrete_tree_graphics->get_node_view() == GraphicsSolidNodeItem::NodeLooks::normal) {
            node->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::user_selected);
            node->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::user_selected);
            selected_nodes << node;
        } else if (node->concrete_tree_graphics->get_node_view() == GraphicsSolidNodeItem::NodeLooks::user_selected) {
            node->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::normal);
            node->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::normal);
            selected_nodes.removeOne(node);
        }

        if (selected_nodes.size() == 0) {
            ui_components_frame->disable_operations_buttons();
        } else if (selected_nodes.size() == 1) {
            ui_components_frame->disable_operations_buttons();

            ui_components_frame->ui->pushButtonCut->setEnabled(true);
            ui_components_frame->ui->pushButtonExpose->setEnabled(true);
        } else if (selected_nodes.size() == 2) {
            ui_components_frame->disable_operations_buttons();
            ui_components_frame->ui->pushButtonLink->setEnabled(true);
            ui_components_frame->ui->pushButtonLCA->setEnabled(true);
        } else if (selected_nodes.size() == 3) {
            selected_nodes.first()->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::normal);
            selected_nodes.first()->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::normal);
            selected_nodes.pop_front();
        }
    }
}

void MainWindow::fit_tree_in_view()
{
    QRectF need = ui->graphicsView->scene()->itemsBoundingRect();
    ui->graphicsView->setSceneRect(need);

    QRectF curr = ui->graphicsView->mapToScene(ui->graphicsView->rect()).boundingRect();

    if (need.width() >= curr.width() || need.height() >= curr.height()) {
        ui->graphicsView->fitInView(ui->graphicsView->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
    } else {
        ui->graphicsView->resetTransform();
        QRectF after = ui->graphicsView->mapToScene(ui->graphicsView->rect()).boundingRect();
        if (need.width() >= after.width() || need.height() >= after.height()) {
            ui->graphicsView->fitInView(ui->graphicsView->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
        }
    }
}





