#include "AbstractNode.h"
#include "Tree/Node.h"

AbstractNode::AbstractNode(Node *my_node)
{
    this->my_node = my_node;

}

AbstractNode::~AbstractNode()
{

}

bool AbstractNode::is_prefered_child()
{
    return my_node->is_prefered_child();
}

int AbstractNode::traverse_and_draw(int offset, int depth)
{
    int width = 1;
    for (AbstractNode * chlid : children) {
        width += chlid->traverse_and_draw(offset, depth + 1);
        offset += 1;
    }
    this->graphics->update_position(offset + width / 2, depth);
    return width;
}

void AbstractNode::reset()
{
    this->children.clear();
    this->parent = nullptr;
}
