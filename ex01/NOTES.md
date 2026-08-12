container used is std::map, because it is an ordered container, and the requirement is to have a container with a key lookup and using the container's own ordering with no manual sort.

 it sorts the key value nodes in the key's ascending order, in this case the key is an int, so it sorts from the smallest int value.