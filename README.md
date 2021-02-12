# Link-Cut-Treeez

Link cut trees visualization.

# Abstract/represented tree
![](pics/abstract_tree.gif)

# Concrete/auxiliary tree
![](pics/concrete_tree.gif)

# A brief explanation of what it is
Link cut tree alows to perform the following operations in O(log(n)) amortized time:
- path-aggregate operations (on the path form a node to its root)
  - sum(v)
  - min(v)
  - max(v)
- find_root(v)
- LCA(v, u);
- add_const(v) (not implemented) - add a constant to each node on the path from v to the root

### Abstract or represented tree
Abstract tree is not stored in the memory; it's just the way we imagine a link-cut tree when working with it. 
Each node can have an unlimited number of children and one prefered child (has a red edge on the visualization).
A chain of preferred children forms a preferred path. 
splay(v) seelects all the edges on the path from v to its root to make the path prefered.
The path-aggregate operations described above are performed on a those prefered paths.

### Concrete or auxiliary tree
The way link-cut tree is actually storred in the memory.
A forest of splay trees where each splay tree represents a phrefered path in the Abstract tree.
The root of each splay tree contains a pointer (path-parent pointer) to its predecessor in the abstract tree.

# You can look at the developement proggress from scratch below
## Update1:
![](pics/progress_so_far.gif?raw=true "Title")

## Update2:
![](pics/update2.gif?raw=true "Title")

## Update3
![](pics/update3.gif?raw=true "Title")

## Update4

![](pics/Update4.gif?raw=true "Title")

## Update5
![](pics/Update5.gif?raw=true "Title")

## Update6
![](pics/Update6.gif?raw=true "Title")
