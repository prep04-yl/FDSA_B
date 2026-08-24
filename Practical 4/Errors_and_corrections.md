##### Problem 4.1

I faced a problem where I changed the pointer before saving the next node which led to losing of the rest of the nodes.

Also when inserting at given position, I placed the new node at incorrect postion which I then resolved it.



##### Problem 4.2

I faced incorrect updation of prev, curr and next pointers which led to an unwanted list order. I learned to first save next, reverse curr->next, move prev and then move curr.

