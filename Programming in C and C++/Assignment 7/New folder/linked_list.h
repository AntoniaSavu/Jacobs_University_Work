struct list;
struct list *push_front(struct list *my_list, int value);
struct list *rem(struct list *my_list);
struct list *push_back(struct list *my_list, int value);
void print_list(struct list *my_list);
void dispose_list(struct list *my_list);
