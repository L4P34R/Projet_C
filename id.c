#include "id.h"

unsigned int global_id;
unsigned int get_next_id(){
    return ++global_id;
}

