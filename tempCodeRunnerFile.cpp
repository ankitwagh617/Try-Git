void tree ::operator=(tree &t1)
{

    root = copytree(t1.root);
}