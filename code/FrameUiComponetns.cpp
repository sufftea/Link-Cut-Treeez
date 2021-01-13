#include "FrameUiComponetns.h"
#include "ui_FrameUiComponetns.h"

FrameUiComponetns::FrameUiComponetns(GraphicsLinkCutTree &graphics_tree,
                                     QQueue<Node *> &selected_nodes,
                                     QGraphicsView * graphicsView,
                                     QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameUiComponetns),
    graphics_tree(graphics_tree),
    selected_nodes(selected_nodes)
{
    ui->setupUi(this);


    // initialize stuff
    this->tree = & graphics_tree.tree;
    this->graphics_view_ui = graphicsView;

    // layouts
    ui->gridLayoutPopUpMenu->setParent(nullptr);
    ui->gridLayoutTopPart->addLayout(ui->gridLayoutPopUpMenu, 0, 0);
    ui->gridLayoutPopUpMenu->setParent(ui->gridLayoutTopPart);

    ui->gridLayoutPopUpDialog->setParent(nullptr);
    ui->gridLayoutTopPart->addLayout(ui->gridLayoutPopUpDialog, 0, 0);
    ui->gridLayoutPopUpDialog->setParent(ui->gridLayoutTopPart);

    ui->scrollAreaLog->stackUnder(ui->framePresetsList);


    // other
    ui->horizontalSliderAnimationSpeed->setValue(50);

    disable_operations_buttons();

    ui->framePresetsList->setMaximumHeight(0);

    ui->labelSequence->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->framePopUpDialog->setMaximumHeight(0);

    // animations
    showPresetsListAnimation = new QPropertyAnimation(this);
    showPresetsListAnimation->setPropertyName("maximumHeight");
    showPresetsListAnimation->setTargetObject(ui->framePresetsList);
    showPresetsListAnimation->setEasingCurve(QEasingCurve::OutExpo);
    showPresetsListAnimation->setDuration(300);
    showPresetsListAnimation->setEndValue(170);

    hidePresetsListAnimation = new QPropertyAnimation(this);
    hidePresetsListAnimation->setPropertyName("maximumHeight");
    hidePresetsListAnimation->setTargetObject(ui->framePresetsList);
    hidePresetsListAnimation->setEasingCurve(QEasingCurve::OutExpo);
    hidePresetsListAnimation->setDuration(300);
    hidePresetsListAnimation->setEndValue(0);


    showPopUpDialogAnimation = new QPropertyAnimation(this);
    showPopUpDialogAnimation->setPropertyName("maximumHeight");
    showPopUpDialogAnimation->setTargetObject(ui->framePopUpDialog);
    showPopUpDialogAnimation->setEasingCurve(QEasingCurve::OutExpo);
    showPopUpDialogAnimation->setDuration(300);
    showPopUpDialogAnimation->setEndValue(200);

    hidePopUpDialogAnimation = new QPropertyAnimation(this);
    hidePopUpDialogAnimation->setPropertyName("maximumHeight");
    hidePopUpDialogAnimation->setTargetObject(ui->framePopUpDialog);
    hidePopUpDialogAnimation->setEasingCurve(QEasingCurve::OutExpo);
    hidePopUpDialogAnimation->setDuration(300);
    hidePopUpDialogAnimation->setEndValue(0);
}

FrameUiComponetns::~FrameUiComponetns()
{
    delete ui;
}

void FrameUiComponetns::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void FrameUiComponetns::mouseMoveEvent(QMouseEvent *e)
{
    e->ignore();
}

void FrameUiComponetns::mouseReleaseEvent(QMouseEvent *e)
{
    e->ignore();
}

void FrameUiComponetns::on_pushButtonMakeStep_clicked()
{
    tree->make_step();
    ui->labelSequence->setText(SequenceLog::get_text());
    graphics_tree.update_scene();

    ui->scrollAreaLog->verticalScrollBar()->setSliderPosition(ui->scrollAreaLog->height());
}

void FrameUiComponetns::on_horizontalSliderAnimationSpeed_valueChanged(int value)
{
    graphics_tree.set_animation_speed(qreal(value) / 100.0);
}

void FrameUiComponetns::on_pushButtonReset_clicked()
{
    reset_tree();
}

void FrameUiComponetns::reset_tree()
{
    selected_nodes.clear();

    graphics_tree.init(8);
    graphics_tree.update_scene();

    SequenceLog::clear();
    ui->labelSequence->setText(SequenceLog::get_text());

    selected_nodes.clear();
}

void FrameUiComponetns::disable_operations_buttons()
{
    for (QPushButton *button : ui->frameOperationsButtons->findChildren<QPushButton *>()) {
        button->setEnabled(false);
    }
}

void FrameUiComponetns::on_pushButtonExpose_clicked()
{
    if (selected_nodes.size() == 1) {
        selected_nodes[0]->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::normal);
        selected_nodes[0]->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::normal);

        tree->finish_operation();
        SequenceLog::clear();
        tree->start_expose(selected_nodes[0]);
        ui->labelSequence->setText(SequenceLog::get_text());

        graphics_tree.update_scene();

        selected_nodes.clear();

        disable_operations_buttons();
    }
}

void FrameUiComponetns::on_pushButtonCut_clicked()
{
    if (selected_nodes.size() == 1) {
        tree->finish_operation();
        SequenceLog::clear();

        tree->start_cut(selected_nodes[0]);

        selected_nodes[0]->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::normal);
        selected_nodes[0]->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::normal);
        selected_nodes.clear();

        disable_operations_buttons();
    }
}

void FrameUiComponetns::on_pushButtonLink_clicked()
{
    if (selected_nodes.size() == 2) {
        tree->finish_operation();
        SequenceLog::clear();

        tree->start_link(selected_nodes[0], selected_nodes[1]);

        ui->labelSequence->setText(SequenceLog::get_text());

        selected_nodes[0]->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::normal);
        selected_nodes[1]->concrete_tree_graphics->set_node_view(GraphicsSolidNodeItem::NodeLooks::normal);
        selected_nodes[0]->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::normal);
        selected_nodes[1]->abstract.graphics->set_view_type(GraphicsAbstractNodeItem::ViewType::normal);

        selected_nodes.clear();

        disable_operations_buttons();
    }
}



void FrameUiComponetns::on_pushButtonEndOperation_clicked()
{
    tree->finish_operation();
    graphics_tree.update_scene();
    ui->labelSequence->setText(SequenceLog::get_text());

    ui->scrollAreaLog->verticalScrollBar()->setSliderPosition(ui->scrollAreaLog->height());
}

void FrameUiComponetns::on_pushButtonOpenPresets_clicked()
{
    if (ui->framePresetsList->maximumHeight() > 0) {
        hidePresetsListAnimation->start();
    } else {
        showPresetsListAnimation->start();
    }
}


void FrameUiComponetns::on_pushButtonPreset1_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();

    graphics_tree.init(14);

    QVector<Node*> &nodes = tree->nodes;

    tree->link(nodes[1], nodes[0]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[2]);
    tree->link(nodes[4], nodes[1]);
    tree->link(nodes[5], nodes[4]);
    tree->link(nodes[6], nodes[5]);
    tree->link(nodes[7], nodes[5]);
    tree->link(nodes[8], nodes[7]);
    tree->link(nodes[9], nodes[8]);
    tree->link(nodes[10], nodes[9]);
    tree->link(nodes[11], nodes[8]);
    tree->link(nodes[12], nodes[11]);
    tree->link(nodes[13], nodes[12]);

    tree->expose(nodes[13]);
    tree->expose(nodes[10]);
    tree->expose(nodes[6]);
    tree->expose(nodes[3]);
    tree->expose(nodes[12]);
    tree->expose(nodes[2]);

    for (Node * node : tree->nodes) {
        node->value = qrand() & 100;
    }

    graphics_tree.update_scene();
}

void FrameUiComponetns::on_pushButtonPreset2_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();

    graphics_tree.init(26);

    QVector<Node*> &nodes = tree->nodes;

    for (Node * node : nodes) {
        node->value = qrand() & 100;
    }

    tree->link(nodes[1], nodes[0]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[2]);
    tree->link(nodes[4], nodes[3]);
    tree->link(nodes[5], nodes[4]);
    tree->link(nodes[6], nodes[2]);
    tree->link(nodes[7], nodes[6]);

    tree->link(nodes[8], nodes[5]);
    tree->link(nodes[9], nodes[8]);
    tree->link(nodes[10], nodes[9]);

    tree->link(nodes[11], nodes[5]);
    tree->link(nodes[12], nodes[11]);
    tree->link(nodes[13], nodes[12]);
    tree->link(nodes[14], nodes[13]);

    tree->link(nodes[15], nodes[5]);
    tree->link(nodes[16], nodes[15]);
    tree->link(nodes[17], nodes[16]);
    tree->link(nodes[18], nodes[17]);
    tree->link(nodes[19], nodes[18]);

    tree->link(nodes[20], nodes[7]);
    tree->link(nodes[21], nodes[20]);
    tree->link(nodes[22], nodes[21]);
    tree->link(nodes[23], nodes[22]);
    tree->link(nodes[24], nodes[23]);
    tree->link(nodes[25], nodes[24]);


    tree->expose(nodes[10]);
    tree->expose(nodes[14]);
    tree->expose(nodes[19]);
    tree->expose(nodes[25]);
    tree->expose(nodes[11]);
    tree->expose(nodes[22]);
    tree->expose(nodes[6]);
    tree->expose(nodes[2]);
    tree->expose(nodes[13]);
    tree->expose(nodes[9]);

    graphics_tree.update_scene();
}

void FrameUiComponetns::on_pushButtonPreset3_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();

    graphics_tree.init(21);

    QVector<Node*> &nodes = tree->nodes;

    for (Node * node : nodes) {
        node->value = qrand() % 100;
    }

    tree->link(nodes[1], nodes[0]);
    tree->link(nodes[2], nodes[0]);
    tree->link(nodes[3], nodes[0]);
    tree->link(nodes[4], nodes[1]);
    tree->link(nodes[5], nodes[2]);
    tree->link(nodes[6], nodes[2]);
    tree->link(nodes[7], nodes[2]);
    tree->link(nodes[8], nodes[3]);
    tree->link(nodes[9], nodes[4]);
    tree->link(nodes[10], nodes[5]);
    tree->link(nodes[11], nodes[6]);
    tree->link(nodes[12], nodes[6]);
    tree->link(nodes[13], nodes[7]);
    tree->link(nodes[14], nodes[8]);
    tree->link(nodes[15], nodes[10]);
    tree->link(nodes[16], nodes[11]);
    tree->link(nodes[17], nodes[12]);
    tree->link(nodes[18], nodes[13]);
    tree->link(nodes[19], nodes[16]);
    tree->link(nodes[20], nodes[17]);

    tree->expose(nodes[9]);
    tree->expose(nodes[15]);
    tree->expose(nodes[19]);
    tree->expose(nodes[20]);
    tree->expose(nodes[18]);
    tree->expose(nodes[14]);
    tree->expose(nodes[5]);
    tree->expose(nodes[3]);

    graphics_tree.update_scene();
}

void FrameUiComponetns::on_pushButtonPreset4_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();

    graphics_tree.init(10);

    QVector<Node*> &nodes = tree->nodes;

    for (Node * node : nodes) {
        node->value = qrand() % 100;
    }

    tree->link(nodes[1], nodes[0]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[1]);
    tree->link(nodes[4], nodes[1]);
    tree->link(nodes[5], nodes[2]);
    tree->link(nodes[6], nodes[2]);
    tree->link(nodes[7], nodes[4]);
    tree->link(nodes[8], nodes[6]);
    tree->link(nodes[9], nodes[7]);

    tree->expose(nodes[8]);

    graphics_tree.update_scene();
}

void FrameUiComponetns::on_pushButtonPreset5_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();

    graphics_tree.init(20);

    QVector<Node*> &nodes = tree->nodes;

    tree->link(nodes[1], nodes[0]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[2]);
    tree->link(nodes[4], nodes[3]);
    tree->link(nodes[5], nodes[4]);
    tree->link(nodes[6], nodes[4]);
    tree->link(nodes[7], nodes[6]);
    tree->link(nodes[8], nodes[7]);
    tree->link(nodes[9], nodes[8]);
    tree->link(nodes[10], nodes[8]);
    tree->link(nodes[11], nodes[9]);
    tree->link(nodes[12], nodes[5]);
    tree->link(nodes[13], nodes[12]);
    tree->link(nodes[14], nodes[13]);
    tree->link(nodes[15], nodes[14]);
    tree->link(nodes[16], nodes[19]);
    tree->link(nodes[17], nodes[15]);
    tree->link(nodes[18], nodes[11]);
    tree->link(nodes[19], nodes[10]);

    tree->expose(nodes[16]);
    tree->expose(nodes[13]);
    tree->expose(nodes[3]);

    graphics_tree.update_scene();
}

void FrameUiComponetns::on_pushButtonPreset6_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonPreset7_clicked()
{
    selected_nodes.clear();
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonClearLog_clicked()
{
    ui->labelSequence->clear();
    SequenceLog::clear();
}

void FrameUiComponetns::on_pushButtonHideLog_clicked()
{
    if (ui->labelSequence->isHidden()) {
        ui->labelSequence->show();
        ui->pushButtonClearLog->show();
        ui->pushButtonHideLog->setText("Hide Log");
    } else {
        ui->labelSequence->hide();
        ui->pushButtonClearLog->hide();
        ui->pushButtonHideLog->setText("Show Log");
    }
}

void FrameUiComponetns::on_pushButtonSwitchTree_clicked()
{
    if (this->current_tree_view == "concrete") {
        this->current_tree_view = "abstract";
        ui->pushButtonSwitchTree->setText("Abstract tree");

        graphics_view_ui->setScene(graphics_tree.get_abstract_tree_scene());

        graphics_tree.activate_abstract_tree_scene();
    } else {
        this->current_tree_view = "concrete";
        ui->pushButtonSwitchTree->setText("Concrete tree");

        graphics_view_ui->setScene(graphics_tree.get_concrete_tree_scene());

        graphics_tree.activate_concrete_tree_scene();
    }
}

void FrameUiComponetns::on_pushButtonPathSum_clicked()
{
    if (graphics_tree.get_displayed_data() == GraphicsSolidNodeItem::NodeData::sum) {
        graphics_tree.set_displayed_data(GraphicsSolidNodeItem::NodeData::value);
        ui->pushButtonPathSum->setStyleSheet(ButtonStyles::switch_button_off);
        return;
    }
    graphics_tree.set_displayed_data(GraphicsSolidNodeItem::NodeData::sum);
    ui->pushButtonPathSum->setStyleSheet(ButtonStyles::switch_button_on);
    ui->pushButtonPathMin->setStyleSheet(ButtonStyles::switch_button_off);
    ui->pushButtonPathMax->setStyleSheet(ButtonStyles::switch_button_off);
}

void FrameUiComponetns::on_pushButtonPathMin_clicked()
{
    if (graphics_tree.get_displayed_data() == GraphicsSolidNodeItem::NodeData::min) {
        graphics_tree.set_displayed_data(GraphicsSolidNodeItem::NodeData::value);
        ui->pushButtonPathMin->setStyleSheet(ButtonStyles::switch_button_off);
        return;
    }
    graphics_tree.set_displayed_data(GraphicsSolidNodeItem::NodeData::min);
    ui->pushButtonPathSum->setStyleSheet(ButtonStyles::switch_button_off);
    ui->pushButtonPathMin->setStyleSheet(ButtonStyles::switch_button_on);
    ui->pushButtonPathMax->setStyleSheet(ButtonStyles::switch_button_off);
}

void FrameUiComponetns::on_pushButtonPathMax_clicked()
{
    if (graphics_tree.get_displayed_data() == GraphicsSolidNodeItem::NodeData::max) {
        graphics_tree.set_displayed_data(GraphicsSolidNodeItem::NodeData::value);
        ui->pushButtonPathMax->setStyleSheet(ButtonStyles::switch_button_off);
        return;
    }
    graphics_tree.set_displayed_data(GraphicsSolidNodeItem::NodeData::max);
    ui->pushButtonPathSum->setStyleSheet(ButtonStyles::switch_button_off);
    ui->pushButtonPathMin->setStyleSheet(ButtonStyles::switch_button_off);
    ui->pushButtonPathMax->setStyleSheet(ButtonStyles::switch_button_on);
}
