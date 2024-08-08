#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status;
};

void sort(struct door* doors, int size);
void initialize_doors(struct door* doors);
void output(struct door* doors, int size);

#endif