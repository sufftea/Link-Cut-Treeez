#include "AbstractNode.h"
#include "Tree/Node.h"

AbstractNode::AbstractNode(Node *my_node)
{
    this->my_solid_node = my_node;
}

AbstractNode::~AbstractNode()
{

}

bool AbstractNode::is_prefered_child()
{
    return my_solid_node->is_prefered_child();
}

int AbstractNode::traverse_and_draw(int offset, int depth)
{
    int width = 0;
    if (this->children.size() == 0) {
        width = 1;
    }

    for (AbstractNode * child : children) {
        width += child->traverse_and_draw(offset + width, depth + 1);
    }

    this->graphics->update_position((double(offset) + double(width - 1) / 2.0) * 2, depth);

    return width;
}

void AbstractNode::reset()
{
    this->children.clear();
    this->parent = nullptr;
}
