#include <stdio.h>
#include "id.h"

unsigned int get_next_id(){
    return ++global_id;
}

